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
        if (numUnlocks == 4) {
            load.allActionLists["leaveShadyPines"][2].setActive(true);
        }
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
                loadRoadToNew(load);
            }
            if (load.allActionLists["leaveShadyPines"][2].checkAction(input)) {
                game.loadScene(load.allAssetsLists["hourglassEdge"], load.allMessageLists["shadyPines"][7], &load.allActionLists["basic"], true);
                game.loadScene(load.allAssetsLists["hourglassEdge"], load.allMessageLists["shadyPines"][8], &load.allActionLists["basic"], true);
                game.loadScene(load.allAssetsLists["hourglassShattered"], load.allMessageLists["shadyPines"][9], &load.allActionLists["basic"], true);
                game.loadScene(load.allAssetsLists["hourglassShattered"], load.allMessageLists["shadyPines"][10], &load.allActionLists["basic"], true);
                game.loadScene(load.allAssetsLists["hourglassShattered"], load.allMessageLists["shadyPines"][11], &load.allActionLists["basic"], true);
                endgame = 1;
            }
        }
        if (endgame == 0) {loadShadyPinesPark(load);}
        
    }

    /**
     * @brief Loads the Main Menu and the subsequent game tutorial.
     */
    

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
        else if (load.allActionLists["libraryActions"][3].checkAction(input)) { talkToSky(load); }
        else if (load.allActionLists["libraryActions"][4].checkAction(input)) {
            game.loadScene(load.allAssetsLists["library"], load.allMessageLists["library"][4], &load.allActionLists["basic"], true);
            load.allActionLists["libraryActions"][4].setActive(false);
            numUnlocks++;
        }
        else if (load.allActionLists["libraryActions"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["library"], load.allMessageLists["library"][2], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["libraryActions"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["library"], load.allMessageLists["library"][3], &load.allActionLists["basic"], true);
            load.allActionLists["powerPlantActions"][2].setActive(true);
            load.allActionLists["libraryActions"][2].setActive(false);
            //unlock the control room here
        }
        
        
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
        else if (load.allActionLists["mcdonaldsActions"][5].checkAction(input)) {
            loadMainStreet(load);
        }
        else if (load.allActionLists["mcdonaldsActions"][4].checkAction(input)) { 
            game.loadScene(load.allAssetsLists["mcdonalds"], load.allMessageLists["mcdonalds"][4], &load.allActionLists["basic"], true);
            load.allActionLists["mcdonaldsActions"][4].setActive(false);
            numUnlocks++;
        }
        
        loadMockdonalds(load);
    }

    void talkToHolden(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["cafe"], load.allMessageLists["holden"][0], &load.allActionLists["talkToHolden"], true);
        if (load.allActionLists["talkToHolden"][3].checkAction(input)) { loadCafe(load); }
        else if (load.allActionLists["talkToHolden"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["cafe"], load.allMessageLists["holden"][1], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["talkToHolden"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["cafe"], load.allMessageLists["holden"][3], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["talkToHolden"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["cafe"], load.allMessageLists["holden"][2], &load.allActionLists["basic"], true);
            load.allActionLists["talkToHolden"][1].setActive(false);
            load.allActionLists["libraryActions"][4].setActive(true);
        }
        
        talkToHolden(load);
    }

    void talkToSky(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["library"], load.allMessageLists["sky"][0], &load.allActionLists["talkToSky"], true);
        if (load.allActionLists["talkToSky"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["library"], load.allMessageLists["sky"][1], &load.allActionLists["basic"], true);
            load.allActionLists["libraryActions"][2].setActive(true);
        }
        else if (load.allActionLists["talkToSky"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["library"], load.allMessageLists["sky"][2], &load.allActionLists["basic"], true);
            game.loadScene(load.allAssetsLists["library"], load.allMessageLists["sky"][3], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["talkToSky"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["library"], load.allMessageLists["sky"][4], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["talkToSky"][3].checkAction(input)) {
            loadLibrary(load);
        }
        talkToSky(load);
    }

    void talkToMax(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["mcdonalds"], load.allMessageLists["max"][0], &load.allActionLists["talkToMax"], true);
        if (load.allActionLists["talkToMax"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["mcdonalds"], load.allMessageLists["max"][1], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["talkToMax"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["mcdonalds"], load.allMessageLists["max"][2], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["talkToMax"][3].checkAction(input)) {
            loadMockdonalds(load);
        }
        else if (load.allActionLists["talkToMax"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["mcdonalds"], load.allMessageLists["max"][3], &load.allActionLists["basic"], true);
            load.allActionLists["talkToMax"][2].setActive(false);
            load.allActionLists["mcdonaldsActions"][4].setActive(true);
        }
        
        talkToMax(load);
    }

    /**
     * @brief Loads the Road To New Slovakia and handles user interactions within the park.
     */
    void loadRoadToNew(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["roadToNew"], load.allMessageLists["roadToNew"][0], &load.allActionLists["roadToNewActions"], true);

        if (load.allActionLists["roadToNewActions"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["roadToNew"], load.allMessageLists["roadToNew"][1], &load.allActionLists["basic"], true);
        }

        else if (load.allActionLists["roadToNewActions"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["roadToNew"], load.allMessageLists["roadToNew"][2], &load.allActionLists["basic"], true);
        }

        else if (load.allActionLists["roadToNewActions"][3].checkAction(input)) {
            input = game.loadScene(load.allAssetsLists["roadToNew"], "Where do you want to go?", &load.allActionLists["leaveRoadToNew"], true);
            //Shady Pines Park, 66 Motel, Legion Farms, Grampa’s Mystery Barn
            if (load.allActionLists["leaveRoadToNew"][0].checkAction(input)) { loadShadyPinesPark(load); }
            if (load.allActionLists["leaveRoadToNew"][1].checkAction(input)) { loadMotel(load); }
            if (load.allActionLists["leaveRoadToNew"][2].checkAction(input)) { loadFarm(load); }
            if (load.allActionLists["leaveRoadToNew"][3].checkAction(input)) { loadBarn(load); }
        }

        else if (load.allActionLists["roadToNewActions"][2].checkAction(input))
        {
            game.loadScene(load.allAssetsLists["roadToNew"], load.allMessageLists["roadToNew"][3], &load.allActionLists["basic"], true);
            game.loadScene(load.allAssetsLists["roadToNew"], load.allMessageLists["roadToNew"][4], &load.allActionLists["basic"], true);
            load.allActionLists["roadToNewActions"][2].setActive(false);
        }

        

        loadRoadToNew(load);
    }

    /**
     * @brief Loads the Road To New Slovakia and handles user interactions within the park.
     */
    void loadMotel(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["motel"], load.allMessageLists["motel"][0], &load.allActionLists["motelActions"], true);

        if (load.allActionLists["motelActions"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["motel"], load.allMessageLists["motel"][1], &load.allActionLists["basic"], true);
        }

        else if (load.allActionLists["motelActions"][1].checkAction(input)) {
            load.allActionLists["motelActions"][1].setActive(false);
            load.allActionLists["talkToMax"][2].setActive(true);
            game.loadScene(load.allAssetsLists["motel"], load.allMessageLists["motel"][2], &load.allActionLists["basic"], true);
        }

        else if (load.allActionLists["motelActions"][3].checkAction(input)) {
            talkToBetsy(load);
        }

        else if (load.allActionLists["motelActions"][4].checkAction(input)) {
            loadRoadToNew(load);
        }

        else if (load.allActionLists["motelActions"][2].checkAction(input))
        {
            game.loadScene(load.allAssetsLists["motel"], load.allMessageLists["motel"][3], &load.allActionLists["basic"], true);

            
        }

        

        loadMotel(load);
    }

    void talkToBetsy(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["motel"], load.allMessageLists["betsy"][0], &load.allActionLists["talkToBetsy"], true);
        if (load.allActionLists["talkToBetsy"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["motel"], load.allMessageLists["betsy"][1], &load.allActionLists["basic"], true);
            game.loadScene(load.allAssetsLists["motel"], load.allMessageLists["betsy"][2], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["talkToBetsy"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["motel"], load.allMessageLists["betsy"][3], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["talkToBetsy"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["motel"], load.allMessageLists["betsy"][4], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["talkToBetsy"][3].checkAction(input)) {
            loadMotel(load);
        }
        talkToBetsy(load);
    }

    void loadBarn(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["mysteryBarn"], load.allMessageLists["barn"][0], &load.allActionLists["barnActions"], true);

        if (load.allActionLists["barnActions"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["mysteryBarn"], load.allMessageLists["barn"][1], &load.allActionLists["basic"], true);
            game.loadScene(load.allAssetsLists["mysteryBarn"], load.allMessageLists["barn"][2], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["barnActions"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["mysteryBarn"], load.allMessageLists["barn"][3], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["barnActions"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["mysteryBarn"], load.allMessageLists["barn"][4], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["barnActions"][3].checkAction(input)) {
            talkToEmeliz(load);
        }
        else if (load.allActionLists["barnActions"][5].checkAction(input)) {
            loadRoadToNew(load);
        }
        else if (load.allActionLists["barnActions"][4].checkAction(input)) {
            game.loadScene(load.allAssetsLists["mysteryBarn"], load.allMessageLists["barn"][5], &load.allActionLists["basic"], true);
            load.allActionLists["barnActions"][4].setActive(false);
            numUnlocks++;
        }
        
        loadBarn(load);
    }

    void talkToEmeliz(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["mysteryBarn"], load.allMessageLists["emeliz"][0], &load.allActionLists["talkToEmeliz"], true);
        
        if (load.allActionLists["talkToEmeliz"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["mysteryBarn"], load.allMessageLists["emeliz"][1], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["talkToEmeliz"][2].checkAction(input)) {
            loadBarn(load);
        }
        else if (load.allActionLists["talkToEmeliz"][1].checkAction(input)) {
            
            if (hasPoster == true) {
                game.loadScene(load.allAssetsLists["mysteryBarn"], load.allMessageLists["emeliz"][3], &load.allActionLists["basic"], true);
                load.allActionLists["talkToEmeliz"][1].setActive(false);
                load.allActionLists["barnActions"][4].setActive(true);
            }
            else {
                game.loadScene(load.allAssetsLists["mysteryBarn"], load.allMessageLists["emeliz"][4], &load.allActionLists["basic"], true);
            }
        }
        

        talkToEmeliz(load);
    }

    void loadFarm(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["farm"], load.allMessageLists["farm"][0], &load.allActionLists["farmActions"], true);

        if (load.allActionLists["farmActions"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["farm"], load.allMessageLists["farm"][1], &load.allActionLists["basic"], true);
            game.loadScene(load.allAssetsLists["farm"], load.allMessageLists["farm"][2], &load.allActionLists["basic"], true);
        }

        else if (load.allActionLists["farmActions"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["farm"], load.allMessageLists["farm"][4], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["farmActions"][3].checkAction(input)) {
            input = game.loadScene(load.allAssetsLists["farm"], "Where do you want to go?", &load.allActionLists["leaveFarm"], true);
            if (load.allActionLists["leaveFarm"][0].checkAction(input)) {
                loadRoadToNew(load);
            }
            else if (load.allActionLists["leaveFarm"][1].checkAction(input)) {
                loadPowerPlant(load);
            }
        }
        else if (load.allActionLists["farmActions"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["farm"], load.allMessageLists["farm"][3], &load.allActionLists["basic"], true);
            load.allActionLists["farmActions"][1].setActive(false);
            //load.allActionLists["talkToEmeliz"][2].setActive(true);
            hasPoster = true;
        }
        
        loadFarm(load);
    }

    void loadPowerPlant(loadGame load) {
        int input = game.loadScene(load.allAssetsLists["powerPlant"], load.allMessageLists["powerPlant"][0], &load.allActionLists["powerPlantActions"], true);

        if (load.allActionLists["powerPlantActions"][0].checkAction(input)) {
            game.loadScene(load.allAssetsLists["powerPlant"], load.allMessageLists["powerPlant"][1], &load.allActionLists["basic"], true);
            game.loadScene(load.allAssetsLists["powerPlant"], load.allMessageLists["powerPlant"][2], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["powerPlantActions"][1].checkAction(input)) {
            game.loadScene(load.allAssetsLists["powerPlant"], load.allMessageLists["powerPlant"][3], &load.allActionLists["basic"], true);
        }
        else if (load.allActionLists["powerPlantActions"][3].checkAction(input)) {
            loadRoadToNew(load);
        }
        else if (load.allActionLists["powerPlantActions"][2].checkAction(input)) {
            game.loadScene(load.allAssetsLists["powerPlant"], load.allMessageLists["powerPlant"][4], &load.allActionLists["basic"], true);
            game.loadScene(load.allAssetsLists["powerPlant"], load.allMessageLists["powerPlant"][5], &load.allActionLists["basic"], true);
            load.allActionLists["powerPlantActions"][2].setActive(false);
            numUnlocks++;
        }
        
        loadPowerPlant(load);
    }



    

private:
    gameTools game;
    timer t; /**< Timer object for time-based operations. */
    color c; /**< Color object for managing text and background colors. */
    int numUnlocks = 0;
    boolean hasPoster = false;
    int endgame = 0;
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


