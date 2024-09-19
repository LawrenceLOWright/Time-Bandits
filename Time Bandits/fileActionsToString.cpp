#include "fileActionsToString.h"

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono>
#include <vector>
#include <sstream>
#include <string>
#include "character.h"

using namespace std;
using namespace std::chrono;

/**
 * @brief Constructs a fileActionsToString object and loads actions and action maps from files.
 * 
 * @param filename The filename containing actions data.
 * @param filename2 The filename containing action mappings.
 */
fileActionsToString::fileActionsToString(string filename, string filename2) {
    filePath = filename + ".actions";
    filePath2 = filename2 + ".actions";

    actions = getText(filePath);
    createActionMap(filePath2);
}

/**
 * @brief Returns the vector of actions.
 * 
 * @return A vector of action objects.
 */
vector<action> fileActionsToString::getActions() { return actions; }

/**
 * @brief Returns the map of action lists.
 * 
 * @return A map where keys are action names and values are vectors of actions.
 */
map<string, vector<action>> fileActionsToString::getActionMap() { return map; }

/**
 * @brief Retrieves actions from the specified file and stores them in a vector.
 * 
 * @param filePath The file path containing actions data.
 * @return A vector of action objects.
 */
vector<action> fileActionsToString::getText(string filePath) {
    File file = File(filePath);
    file.openFile();

    FileRetrival data = FileRetrival(file);

    for (int x = 0; x < data.size(); x++) {
        action a;
        a.setActionDetails(data.getData(x, 0), data.getData(x, 1));
        actions.push_back(a);
    }

    file.closeFile();
    return actions;
}

/**
 * @brief Creates a map of action lists by associating actions with specific keys from the given file.
 * 
 * @param filePath2 The file path containing action mapping data.
 */
void fileActionsToString::createActionMap(string filePath2) {
    File file = File(filePath2);
    file.openFile();

    FileRetrival data = FileRetrival(file);

    for (int x = 0; x < data.size(); x++) {
        // Create a vector of actions for the current line
        vector<action> actionVec;

        // Iterate through each action in the line
        for (int y = 1; y < data.getData(x).size(); y++) {
            // Check if the current action matches any available action
            for (int a = 0; a < actions.size(); a++) {
                if (data.getData(x, y) == actions[a].getActionName()) {
                    actionVec.push_back(actions[a]);
                    break;
                }
            }
        }

        // Add the action vector to the map with the corresponding key
        map[data.getData(x, 0)] = actionVec;
    }

    file.closeFile();
}
