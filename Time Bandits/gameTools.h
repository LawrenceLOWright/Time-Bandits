#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> 
#include <vector>
#include <map>

#include "character.h"
#include "color.h"
#include "fileToString.h"
#include "fileMessagesToString.h"
#include "fileActionsToString.h"
#include "message.h"
#include "timer.h"
#include "action.h"
#include "actionListener.h"

using namespace std;
using namespace std::chrono;

/**
 * @class gameTools
 * @brief Provides a set of tools to manage game screen, assets, and user actions.
 */
class gameTools {
public:
    /**
     * @brief Refreshes the screen by redrawing content.
     */
    void refreshScreen();

    /**
     * @brief Changes the size of the game screen.
     * 
     * @param width The new width of the screen in characters.
     * @param height The new height of the screen in characters.
     */
    void changeScreenSize(int width, int height);

    /**
     * @brief Loads an asset from a file.
     * 
     * @param fileName The name of the file to load the asset from.
     * @return A vector of characters representing the asset.
     */
    vector<character> loadAsset(string fileName);

    /**
     * @brief Loads the screen with a given set of characters.
     * 
     * @param vec The vector of characters to be displayed on the screen.
     */
    void loadScreen(vector<character> vec);

    /**
     * @brief Loads a scene and presents it to the player.
     * 
     * @param scene A vector of characters representing the scene.
     * @param text The description or story text to display with the scene.
     * @param actions A pointer to a vector of available actions.
     * @return An integer representing the exit status of the scene.
     */
    int loadScene(vector<character> scene, string text, vector<action>* actions);

    /**
     * @brief Loads a scene with an optional action header.
     * 
     * @param scene A vector of characters representing the scene.
     * @param text The description or story text to display with the scene.
     * @param actions A pointer to a vector of available actions.
     * @param actionHeader A boolean indicating whether to include an action header.
     * @return An integer representing the exit status of the scene.
     */
    int loadScene(vector<character> scene, string text, vector<action>* actions, bool actionHeader);

    /**
     * @brief Loads a scene using a message object.
     * 
     * @param scene A vector of characters representing the scene.
     * @param text A message object representing the text to display.
     * @param actions A pointer to a vector of available actions.
     * @param actionHeader A boolean indicating whether to include an action header.
     * @return An integer representing the exit status of the scene.
     */
    int loadScene(vector<character> scene, message text, vector<action>* actions, bool actionHeader);

    /**
     * @brief Loads a scene using a message object.
     * 
     * @param scene A vector of characters representing the scene.
     * @param text A message object representing the text to display.
     * @param actions A pointer to a vector of available actions.
     * @return An integer representing the exit status of the scene.
     */
    int loadScene(vector<character> scene, message text, vector<action>* actions);

    /**
     * @brief Checks for player inputs based on available actions.
     * 
     * @param actions A pointer to a vector of available actions.
     * @return An integer representing the chosen action or key press.
     */
    int checkInputs(vector<action>* actions);

    /**
     * @brief Writes out the available actions for the player.
     * 
     * @param actions A pointer to a vector of available actions.
     * @return A string representing the available actions.
     */
    string writeActions(vector<action>* actions);

    /**
     * @brief Changes the available actions in the current game context.
     * 
     * @param actions A vector of new actions to be set.
     */
    void changeActions(vector<action> actions);

private:
    int screenWidth = 120; /**< The width of the screen in characters. */
    int screenHeight = 200; /**< The height of the screen in characters. */
};
