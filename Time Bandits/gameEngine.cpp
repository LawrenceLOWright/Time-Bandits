#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> 
#include <map>
#include <vector>

#include "character.h"
#include "color.h"
#include "fileToString.h"
#include "fileMessagesToString.h"
#include "fileActionsToString.h"
#include "message.h"
#include "timer.h"
#include "action.h"
#include "actionListener.h"
#include "gameTools.h"
#include "loadGame.h"

#define UNICODE

using namespace std;


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

        // Load actions

        fileActionsToString actionList = fileActionsToString("actionList", "actionCombos");
        vector<action> actions = actionList.getActions();
        allActionLists = actionList.getActionMap();

        // Load messages

        fileMessagesToString messages = fileMessagesToString("shadyPines");

        vector<message> shadyPinesParkMessages = messages.getLines();

        allMessageLists["shadyPines"] = shadyPinesParkMessages;


        // Load assets
        mainMenu = game.loadAsset("mainMenu");
        shadyPinesPark = game.loadAsset("shadyPinesPark");

        loadMainMenu(); // Load main menu

        c.setDefault(); // Reset colors at end
    }

    /**
     * @brief Loads the Shady Pines Park scene and handles user interactions within the park.
     */
    void loadShadyPinesPark() {
        int input = game.loadScene(shadyPinesPark, allMessageLists["shadyPines"][0], allActionLists["shadyPinesParkActions"], true);
        if (input == pickDandelions.getkeyCode() && pickDandelions.isActive()) {
            game.loadScene(shadyPinesPark, allMessageLists["shadyPines"][4], allActionLists["basic"], true);
            pickDandelions.flipActive();
        }
        if (input == swings.getkeyCode()) {
            game.loadScene(shadyPinesPark, allMessageLists["shadyPines"][5], allActionLists["basic"], true);
        }

        loadMainMenu(); // Return to main menu after interaction
    }

    /**
     * @brief Loads the Main Menu and the subsequent game tutorial.
     */
    void loadMainMenu() {
        game.loadScene(mainMenu, "", allActionLists["basic"]);
        game.changeScreenSize(150, 40); // Set screen size
        game.loadScene(mainMenu, allMessageLists["shadyPines"][0], allActionLists["basic"]);
        game.loadScene(mainMenu, allMessageLists["shadyPines"][1], allActionLists["tutorial1"]);
        game.loadScene(shadyPinesPark, allMessageLists["shadyPines"][3], allActionLists["basic"], true);
        loadShadyPinesPark();
    }

private:
    gameTools game;
    action enter, description, pickDandelions, swings; /**< Action objects representing different user actions. */
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
        loadGame load = loadGame();
        game.LoadGame();
        
    }

    // system("@echo off");  // Not used: Placeholder for potential future use
};


