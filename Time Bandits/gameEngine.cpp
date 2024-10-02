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
#include "error.h"

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
    void LoadGame(const loadGame load) {
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

    void loadMainMenu(loadGame load) {
        game.changeScreenSize(150, 40); // Set screen size 151/41 legacy 4 windows 11, 150,40 for other machines
        game.loadScene(load.allAssetsLists["mainMenu"], load.allMessageLists["shadyPines"][0], &load.allActionLists["basic"]);
        game.loadScene(load.allAssetsLists["mainMenu"], load.allMessageLists["shadyPines"][1], &load.allActionLists["tutorial1"]);
        game.loadScene(load.allAssetsLists["shadyPinesPark"], load.allMessageLists["shadyPines"][2], &load.allActionLists["basic"], true);
        loadShadyPinesPark(load);
    }

    /**
     * @brief Loads the Shady Pines Park scene and handles user interactions within the park.
     */
    void loadShadyPinesPark(loadGame load) {
        cout << "Loading shady pines park" << endl;
        int input = game.loadScene(load.allAssetsLists["shadyPinesPark"], load.allMessageLists["shadyPines"][3], &load.allActionLists["shadyPinesParkActions"], true);
        //cout << input;
        if (load.allActionLists["shadyPinesParkActions"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["shadyPinesPark"], load.allMessageLists["shadyPines"][5], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["shadyPinesParkActions"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["shadyPinesPark"], load.allMessageLists["shadyPines"][6], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["shadyPinesParkActions"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["shadyPinesPark"], load.allMessageLists["shadyPines"][4], &load.allActionLists["basic"], true);
            load.allActionLists["shadyPinesParkActions"][0].setActive(false);
        }
        else if (load.allActionLists["shadyPinesParkActions"][3].checkAction(input)) {
            input = game.loadScene(load.allAssetsLists["shadyPinesPark"], "Where do you want to go?", &load.allActionLists["leaveShadyPines"], true);
            if (load.allActionLists["leaveShadyPines"][0].checkAction(input))
            {
                loadMainStreet(load);
            }
            if (load.allActionLists["leaveShadyPines"][1].checkAction(input)) {
                loadSlovokaRoad(load);
            }
        }

        loadShadyPinesPark(load); // Return to main menu after interaction
    }

    /**
     * @brief Loads the Main Menu and the subsequent game tutorial.
     */

    void loadSlovokaRoad(loadGame load) {
        //cout << "Slovoka Road";
        int input = game.loadScene(load.allAssetsLists["roadToNew"], load.allMessageLists["roadToNew"][0], &load.allActionLists["roadToNew"], true);
        if (load.allActionLists["roadToNew"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["roadToNew"], load.allMessageLists["roadToNew"][1], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["roadToNew"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["roadToNew"], load.allMessageLists["roadToNew"][2], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["roadToNew"][3].checkAction(input) || load.allActionLists["roadToNew"][2].checkAction(input) && load.allActionLists["roadToNew"][2].getActionName() == "Leave") {
            input = game.loadScene(load.allAssetsLists["roadToNew"], "Where do you want to go?", &load.allActionLists["leaveRoadToNew"], true);
            if (load.allActionLists["leaveRoadToNew"][0].checkAction(input)) { loadShadyPinesPark(load); }
            else if (load.allActionLists["leaveRoadToNew"][1].checkAction(input)) { load66Motel(load); }
        }
        else if (load.allActionLists["roadToNew"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["roadToNew"], load.allMessageLists["roadToNew"][3], &load.allActionLists["basic"], true);
            load.allActionLists["roadToNew"][2].setActive(false);
        }
        

        loadSlovokaRoad(load);
    }

    void load66Motel(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["motel"], load.allMessageLists["66Motel"][0], &load.allActionLists["66Motel"], true);
        if (load.allActionLists["66Motel"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["motel"], load.allMessageLists["66Motel"][1], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["66Motel"][4].checkAction(input)) {
            input = game.loadScene(load.allAssetsLists["motel"], "Where do you want to go?", &load.allActionLists["leave66Motel"], true);
            if (load.allActionLists["leave66Motel"][0].checkAction(input)) { loadSlovokaRoad(load); }
        }
        else if (load.allActionLists["66Motel"][3].checkAction(input)) {
            game.loadScene(load.allAssetsLists["motel"], load.allMessageLists["66Motel"][4], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["66Motel"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["motel"], load.allMessageLists["66Motel"][3], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["66Motel"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["motel"], load.allMessageLists["66Motel"][2], &load.allActionLists["basic"], true);
            load.allActionLists["66Motel"][1].setActive(false);
        }


        load66Motel(load);
    }
    

    void loadMainStreet(loadGame load){
        int input = game.loadScene(load.allAssetsLists["mainStreet"], load.allMessageLists["mainStreet"][0], &load.allActionLists["mainStreetActions"], true);
        
        if (load.allActionLists["mainStreetActions"][0].checkAction(input)) 
        {game.loadScene(load.allAssetsLists["mainStreet"], load.allMessageLists["mainStreet"][1], &load.allActionLists["basic"], true);}

        else if (load.allActionLists["mainStreetActions"][1].checkAction(input)) 
        {game.loadScene(load.allAssetsLists["mainStreet"], load.allMessageLists["mainStreet"][2], &load.allActionLists["basic"], true);}

        else if (load.allActionLists["mainStreetActions"][3].checkAction(input)) {
            input = game.loadScene(load.allAssetsLists["mainStreet"], "Where do you want to go?", &load.allActionLists["leaveMainStreet"], true);
            //Shady Pines Park,The Kalefe,MockDonald's,Hourglass Public Library
            if (load.allActionLists["leaveMainStreet"][0].checkAction(input)) { loadShadyPinesPark(load); }
            if (load.allActionLists["leaveMainStreet"][1].checkAction(input)) { loadCafe(load); }
            if (load.allActionLists["leaveMainStreet"][2].checkAction(input)) { loadMockdonalds(load); }
            if (load.allActionLists["leaveMainStreet"][3].checkAction(input)) { loadLibrary(load); }
        }

        else if (load.allActionLists["mainStreetActions"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["mainStreet"], load.allMessageLists["mainStreet"][3], &load.allActionLists["basic"], true);
            load.allActionLists["mainStreetActions"][2].setActive(false);
        }
        
        loadMainStreet(load);
    }

    void loadCafe(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["cafe"], load.allMessageLists["cafe"][0], &load.allActionLists["cafeActions"], true);
        if (load.allActionLists["cafeActions"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["cafe"], load.allMessageLists["cafe"][1], &load.allActionLists["basic"], true);
        }
        if (load.allActionLists["cafeActions"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["cafe"], load.allMessageLists["cafe"][2], &load.allActionLists["basic"], true);
        }
        if (load.allActionLists["cafeActions"][2].checkAction(input)) {
            talkToHolden(load);
        }
        if (load.allActionLists["cafeActions"][3].checkAction(input)) {
            loadMainStreet(load);
        }
        loadCafe(load);
    }
    void loadLibrary(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["library"], load.allMessageLists["library"][0], &load.allActionLists["libraryActions"], true);
        if (load.allActionLists["libraryActions"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["library"], load.allMessageLists["library"][1], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["libraryActions"][5].checkAction(input)) { loadMainStreet(load); }
        else if (load.allActionLists["libraryActions"][3].checkAction(input)) {
            game.loadScene(load.allAssetsLists["library"], load.allMessageLists["library"][4], &load.allActionLists["basic"], true);
            load.allActionLists["libraryActions"][3].setActive(false);
        }
        else if (load.allActionLists["libraryActions"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["library"], load.allMessageLists["library"][2], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["libraryActions"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["library"], load.allMessageLists["library"][3], &load.allActionLists["basic"], true);
            //unlock the control room here
        }
        else if (load.allActionLists["libraryActions"][4].checkAction(input)) {talkToSky(load);}
        
        loadLibrary(load);
    }

    void loadMockdonalds(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["mcdonalds"], load.allMessageLists["mcdonalds"][0], &load.allActionLists["mcdonaldsActions"], true);
        if (load.allActionLists["mcdonaldsActions"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["mcdonalds"], load.allMessageLists["mcdonalds"][1], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["mcdonaldsActions"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["mcdonalds"], load.allMessageLists["mcdonalds"][2], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["mcdonaldsActions"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["mcdonalds"], load.allMessageLists["mcdonalds"][3], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["mcdonaldsActions"][3].checkAction(input)) {
            talkToMax(load);
        }
        else if (load.allActionLists["mcdonaldsActions"][4].checkAction(input)) { 
            game.loadScene(load.allAssetsLists["mcdonalds"], load.allMessageLists["mcdonalds"][4], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["mcdonaldsActions"][5].checkAction(input)) {
            loadMainStreet(load);
        }
        loadMockdonalds(load);
    }

    void talkToHolden(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["cafe"], load.allMessageLists["holden"][0], &load.allActionLists["talkToHolden"], true);
        if (load.allActionLists["cafeActions"][3].checkAction(input)) { loadCafe(load); }
        else if (load.allActionLists["cafeActions"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["cafe"], load.allMessageLists["holden"][1], &load.allActionLists["basic"], true);
        }
        
        else if (load.allActionLists["cafeActions"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["cafe"], load.allMessageLists["holden"][2], &load.allActionLists["basic"], true);
            load.allActionLists["talkToHolden"][2].setActive(false);
            load.allActionLists["libraryActions"][4].setActive(true);
        }
        else if (load.allActionLists["cafeActions"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["cafe"], load.allMessageLists["holden"][3], &load.allActionLists["basic"], true);
        }
        
        talkToHolden(load);
    }

    void talkToSky(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["library"], load.allMessageLists["sky"][0], &load.allActionLists["talkToSky"], true);
        if (load.allActionLists["talkToSky"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["library"], load.allMessageLists["sky"][1], &load.allActionLists["talkToSky"], true);
            load.allActionLists["mcdonaldsActions"][2].setActive(true);
        }
        if (load.allActionLists["talkToSky"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["library"], load.allMessageLists["sky"][2], &load.allActionLists["talkToSky"], true);
        }
        if (load.allActionLists["talkToSky"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["library"], load.allMessageLists["sky"][3], &load.allActionLists["talkToSky"], true);
        }
        if (load.allActionLists["talkToSky"][3].checkAction(input)) {
            loadLibrary(load);
        }
        talkToSky(load);
    }

    void talkToMax(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["mcdonalds"], load.allMessageLists["max"][0], &load.allActionLists["talkToMax"], true);
        if (load.allActionLists["talkToMax"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["mcdonalds"], load.allMessageLists["max"][1], &load.allActionLists["talkToMax"], true);
        }
        if (load.allActionLists["talkToMax"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["mcdonalds"], load.allMessageLists["max"][2], &load.allActionLists["talkToMax"], true);
        }
        if (load.allActionLists["talkToMax"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["mcdonalds"], load.allMessageLists["max"][3], &load.allActionLists["talkToMax"], true);
            load.allActionLists["mcdonaldsActions"][4].setActive(true);
        }
        if (load.allActionLists["talkToMax"][3].checkAction(input)) {
            loadMockdonalds(load);
        }
        talkToMax(load);
    }

private:
    gameTools game;
    timer t; /**< Timer object for time-based operations. */
    color c; /**< Color object for managing text and background colors. */
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
    void runGame(const loadGame load) {
        Game game;
        game.LoadGame(load);
        
    }

    // system("@echo off");  // Not used: Placeholder for potential future use
};


