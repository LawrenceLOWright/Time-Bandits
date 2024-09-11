#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> 
#include <map>
#include <vector>

// Not used

// Used

#include "character.h"
#include "color.h"
#include "fileToString.h"
#include "fileMessagesToString.h"
#include "message.h"
#include "timer.h"
#include "action.h"
#include "actionListener.h"

#define UNICODE

using namespace std;
//using namespace std::chrono; // To avoid typing std::chrono:: every time





// =================================================
// Deals with code relating to the screen


// =================================================

/**
 * @brief Handles screen operations such as refreshing, changing size, and loading assets.
 */
class Screen {
public:
    /**
     * @brief Refreshes the screen to a new frame.
     * Clears the console screen using the system "cls" command.
     */
    void refreshScreen() {
        system("cls");
    }

    /**
     * @brief Changes the size of the console screen.
     * 
     * @param width  New width of the console.
     * @param height New height of the console.
     */
    void changeScreenSize(int width, int height) {
        screenWidth = width;
        screenHeight = height;

        std::string command = "mode con: cols=" + std::to_string(screenWidth) + " lines=" + std::to_string(screenHeight);
        system(command.c_str());
    }

    /**
     * @brief Loads character data from a file and returns a vector of characters.
     * 
     * @param fileName Name of the file to load.
     * @return A vector of character objects representing the file content.
     */
    vector<character> loadAsset(string fileName) {
        fileToString f = fileToString(fileName);
        std::vector<character> vec = f.textToChar();
        return vec;
    }

    /**
     * @brief Loads and displays a scene using the vector of character objects.
     * 
     * @param vec Vector of character objects to display.
     */
    void loadScreen(vector<character> vec) {
        //refreshScreen();

        color color;
        int prevCol2 = 999;
        int prevCol = 999;

        for (int x = 0; x < vec.size(); x++) {
            int col2 = vec[x].getBackgroundColor();
            int col = vec[x].getTextColor();
            if (col == prevCol && col2 == prevCol2) { prevCol = col; }
            else {
                prevCol = col;
                prevCol2 = col2;
                color.setCurrentColor(col, col2);
            }

            cout << vec[x].getChar();
        }

        color.setDefault();
        Sleep(100);
    }

    /**
     * @brief Loads a scene, displays text, and waits for user input to trigger actions.
     * 
     * @param scene   Vector of character objects representing the scene.
     * @param text    Additional text to display on the scene.
     * @param actions Vector of action objects representing possible user actions.
     * @return The key code of the action performed.
     */
    int loadScene(vector<character> scene, string text, vector<action> actions) {
        int keyCode = 0;
        actionListener action;

        loadScreen(scene);
        cout << text << endl;

        while (true) {
            keyCode = action.codeInputListener();

            // Check if certain button is pressed
            for (int x = 0; x < actions.size(); x++) {
                if (actions[x].checkAction(keyCode) == true) { return keyCode; }
            }
        }
    }

    /**
     * @brief Loads a scene with an action header, displays text, and waits for user input.
     * 
     * @param scene        Vector of character objects representing the scene.
     * @param text         Additional text to display on the scene.
     * @param actions      Vector of action objects representing possible user actions.
     * @param actionHeader Boolean flag to indicate whether to show the action header.
     * @return The key code of the action performed.
     */
    int loadScene(vector<character> scene, string text, vector<action> actions, bool actionHeader) {
        int keyCode = 0;
        actionListener action;
        string header = " <     Available Actions : ";

        for (int e = 0; e < actions.size(); e++) {
            if (actions[e].isActive()) {
                header = header + " [" + actions[e].getKeyCodeName() + " : " + actions[e].getActionName() + "]";
            }
            
        }

        loadScreen(scene);
        cout << header + "\n---------------" << endl;
        cout << text << endl;

        while (true) {
            keyCode = action.codeInputListener();

            // Check if certain button is pressed
            for (int x = 0; x < actions.size(); x++) {
                if (actions[x].isActive())
                {
                    if (actions[x].checkAction(keyCode) == true) { return keyCode; }
                }
            }
        }
    }

private:
    int screenWidth = 120; /**< The width of the screen in characters. */
    int screenHeight = 200; /**< The height of the screen in characters. */
};


// =================================================
// Deals with the game script


// =================================================
/**
 * @brief Manages the game logic, including loading game details, actions, and scenes.
 */
class Game {
public:
    /**
     * @brief Initializes the game, loads assets, and starts the game sequence.
     */
    void LoadGame() {
        system("chcp 65001"); // Set the encoding to UTF-8 for cmd
        screen.changeScreenSize(150, 40); // Set screen size

        // Load actions
        enter.setActionDetails("Continue", "enter", 13);
        description.setActionDetails("Description", "D", 68);
        pickDandelions.setActionDetails("Pick Dandelions", "1", 49);
        swings.setActionDetails("Sit on Swings", "2", 50);

        vector<action> basic{ enter };
        vector<action> basicArea{ enter, description };
        vector<action> tutorial1{ description };
        vector<action> shadyPinesParkActions{ enter, description, pickDandelions, swings };

        allActionLists["basic"] = basic;
        allActionLists["basicArea"] = basicArea;
        allActionLists["tutorial1"] = tutorial1;
        allActionLists["shadyPinesParkActions"] = shadyPinesParkActions;

        // Load messages

        fileMessagesToString messages = fileMessagesToString("shadyPines");

        vector<message> shadyPinesParkMessages = messages.getLines();

        allMessageLists["shadyPines"] = shadyPinesParkMessages;

        
        for (int x = 0; x < shadyPinesParkMessages.size(); x++) {
            cout << "HELLO";
            cout << shadyPinesParkMessages[x].getMessage();
        }

        // Load assets
        mainMenu = screen.loadAsset("mainMenu");
        shadyPinesPark = screen.loadAsset("shadyPinesPark");

        loadMainMenu(); // Load main menu

        c.setDefault(); // Reset colors at end
    }

    /**
     * @brief Loads the Shady Pines Park scene and handles user interactions within the park.
     */
    void loadShadyPinesPark() {
        int input = screen.loadScene(shadyPinesPark, allMessageLists["shadyPines"][2].getMessage(), allActionLists["shadyPinesParkActions"], true);
        if (input == pickDandelions.getkeyCode() && pickDandelions.isActive()) {
            screen.loadScene(shadyPinesPark, allMessageLists["shadyPines"][4].getMessage(), allActionLists["basic"], true);
            pickDandelions.flipActive();
        }
        if (input == swings.getkeyCode()) {
            screen.loadScene(shadyPinesPark, allMessageLists["shadyPines"][5].getMessage(), allActionLists["basic"], true);
        }

        loadMainMenu(); // Return to main menu after interaction
    }

    /**
     * @brief Loads the Main Menu and the subsequent game tutorial.
     */
    void loadMainMenu() {
        screen.loadScene(mainMenu, "", allActionLists["basic"]);
        screen.changeScreenSize(150, 50);
        screen.loadScene(mainMenu, allMessageLists["shadyPines"][0].getMessage(), allActionLists["basic"]);
        screen.loadScene(mainMenu, allMessageLists["shadyPines"][1].getMessage(), allActionLists["tutorial1"]);
        screen.loadScene(shadyPinesPark, allMessageLists["shadyPines"][3].getMessage(), allActionLists["basic"], true);
        loadShadyPinesPark();
    }

private:
    action enter, description, pickDandelions, swings; /**< Action objects representing different user actions. */
    Screen screen; /**< Screen object to manage screen operations. */
    timer t; /**< Timer object for time-based operations. */
    color c; /**< Color object for managing text and background colors. */
    vector<character> mainMenu; /**< Vector of character objects representing the main menu. */
    vector<character> shadyPinesPark; /**< Vector of character objects representing Shady Pines Park. */
    map<string, vector<action>> allActionLists; /**< Map of action lists for different scenes. */
    map<string, vector<message>> allMessageLists; /**< list of all different messages for */
};


// ===============================================================
// MAIN CODE
// ===============================================================

/**
 * @brief Entry point for the game. Manages game initialization and execution.
 */
class gameEngine {
public:
    /**
     * @brief Starts the game by creating a Game object and loading the game.
     * 
     * This function initializes the game by creating an instance of the `Game` class
     * and calling its `LoadGame()` method. The game loop and all initializations
     * are managed within the `Game` class.
     */
    void runGame() {
        Game game;
        game.LoadGame();
    }

    // system("@echo off");  // Not used: Placeholder for potential future use
};


