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
    void LoadGame(loadGame load) {
        //system("chcp 65001"); // Set the encoding to UTF-8 for cmd
        //game.changeScreenSize(150, 40); // Set screen size

        // Load actions

        //fileActionsToString actionList = fileActionsToString("actionList", "actionCombos");
        //vector<action> actions = actionList.getActions();
        //allActionLists = actionList.getActionMap();

        // Load messages

        //fileMessagesToString messages = fileMessagesToString("shadyPines");
        //vector<message> shadyPinesParkMessages = messages.getLines();
        //allMessageLists["shadyPines"] = shadyPinesParkMessages;


        // Load assets
        //mainMenu = game.loadAsset("mainMenu");
        //shadyPinesPark = game.loadAsset("shadyPinesPark");
        loadMainMenu(load); // Load main menu


        c.setDefault(); // Reset colors at end
    }

    /**
     * @brief Loads the Shady Pines Park scene and handles user interactions within the park.
     */
    void loadShadyPinesPark(loadGame load) {
        cout << "Loading shady pines park" << endl;
        int input = game.loadScene(load.allAssetsLists["shadyPinesPark"], load.allMessageLists["shadyPines"][3], load.allActionLists["shadyPinesParkActions"], true);
        cout << input;
        if (allActionLists["shadyPinesParkActions"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["shadyPinesPark"], load.allMessageLists["shadyPines"][4], load.allActionLists["basic"], true);
            pickDandelions.setActive(false);
        }
        if (allActionLists["shadyPinesParkActions"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["shadyPinesPark"], load.allMessageLists["shadyPines"][5], load.allActionLists["basic"], true);
        }

        loadMainMenu(load); // Return to main menu after interaction
    }

    /**
     * @brief Loads the Main Menu and the subsequent game tutorial.
     */
    void loadMainMenu(loadGame load) {
        game.changeScreenSize(151, 41); // Set screen size 151/41 legacy 4 windows 11, 150,40 for other machines
        game.loadScene(load.allAssetsLists["mainMenu"], load.allMessageLists["shadyPines"][0], load.allActionLists["basic"]);
        game.loadScene(load.allAssetsLists["mainMenu"], load.allMessageLists["shadyPines"][1], load.allActionLists["tutorial1"]);
        game.loadScene(load.allAssetsLists["shadyPinesPark"], load.allMessageLists["shadyPines"][2], load.allActionLists["basic"], true);
        loadShadyPinesPark(load);
    }

    void loadMainStreet(loadGame load){
        
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
    void runGame(loadGame load) {
        Game game;
        game.LoadGame(load);
        
    }

    // system("@echo off");  // Not used: Placeholder for potential future use
};


