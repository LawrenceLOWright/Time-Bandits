#include "loadGame.h"

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header
#include <vector>
#include <map>
#include <sstream>

/**
 * @class loadGame
 * @brief Class responsible for loading game settings, actions, assets, and running the game loop.
 */
loadGame::loadGame() {}

/**
 * @brief Loads the game settings and starts the game loop.
 * 
 * This function reads the game settings, loads the actions, messages, and assets, and then calls the 
 * function pointer `startGame` to run the game loop.
 * 
 * @param startGame A function pointer that runs the game. It takes two arguments: the loadGame instance and a gameTools instance.
 */
void loadGame::load(int (*startGame) (loadGame load, gameTools game)) {
    // Set the encoding
    string str = retrieveSetting("Encoding");
    const char* cstr = str.c_str();
    system(cstr);

    // Set Game Screen Size
    gameTools game;
    std::stringstream ss(retrieveSetting("ScreenWidth"));
    std::stringstream ss2(retrieveSetting("ScreenHeight"));
    int num, num2;
    //cout << "num1: " << ss.str() << ";" << num << endl;
    ss >> num;
    ss2 >> num2;
    game.changeScreenSize(160, 40);
    
    //return;

    // Get Actions for the game
    fileActionsToString actionList = fileActionsToString("actionList", "actionCombos");
    actions = actionList.getActions();
    allActionLists = actionList.getActionMap();

    // Get Messages for the game
    fileTextToString messageList = fileTextToString("messageList");
    allMessageLists = messageList.allMessageLists;

    // Get all assets for the game
    fileAssetsToString assetList = fileAssetsToString("assets");
    allAssetsLists = assetList.allAssetsLists;

    // Hard coded actions for special inputs 
    action cont;
    action desc;

    cont.setActionDetails("Continue", "1", "enter", 13);
    desc.setActionDetails("Description", "1", "D", 68);

    vector<action> basic = { cont };
    vector<action> basicArea = { cont, desc };
    vector<action> tutorial1 = { desc };

    allActionLists["basic"] = basic;
    allActionLists["basicArea"] = basicArea;
    allActionLists["tutorial1"] = tutorial1;

    // Set color to default
    color c;
    c.setDefault();

    // Run the game
    int exit = 1;
    while (exit == 1) {
        exit = startGame(*this, game);
    }
}

/**
 * @brief Retrieves a specific game setting from the settings file.
 * 
 * This function looks for a setting by name in the `settings.info` file and returns its value.
 * 
 * @param settingName The name of the setting to retrieve.
 * @return A string representing the value of the requested setting, or "Nothing" if not found.
 */
string loadGame::retrieveSetting(const string settingName) {
    string filePath = "settings.info";
    File file = File(filePath);

    string lines = "";
    string tp = "";
    int num = 1;
    while (getline(file.file, tp)) {
        stringstream details(tp);
        string segment1 = "";

        while (getline(details, segment1, ',')) {
            if (settingName == segment1) {
                getline(details, segment1, ',');
                return segment1;
                break;
            }
        }
    }

    file.closeFile();
    return "Nothing";
}

/* 
int loadGame::loadScene(string sceneName, int location) {
    gameTools game;
    return game.loadScene(allAssetsLists["shadyPines"], allMessageLists[sceneName][location], allActionLists[sceneName + to_string(location)]);
}
*/