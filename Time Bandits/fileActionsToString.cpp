#include "fileActionsToString.h"

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header
#include <vector>
#include <sstream>
#include <string>
#include "character.h"

using namespace std;
using namespace std::chrono;

fileActionsToString::fileActionsToString(string filename, string filename2) {
	filePath = filename + ".actions";
    filePath2 = filename2 + ".actions";

    actions = getText(filePath);
    createActionMap(filePath2);
}

vector<action> fileActionsToString::getActions() { return actions;}
map<string, vector<action>> fileActionsToString::getActionMap() { return map; }

vector<action> fileActionsToString::getText(string filePath) {
    File file = File(filePath);
    file.openFile();

    FileRetrival data = FileRetrival(file);

    for (int x = 0; x < data.size(); x++) {
        action a;
        a.setActionDetails(data.getData(x,0), data.getData(x,1));
        actions.push_back(a);
    }

    file.closeFile();
    return actions;
};

void fileActionsToString::createActionMap(string filePath2) {
    File file = File(filePath2);
    file.openFile();

    FileRetrival data = FileRetrival(file);
    for (int x = 0; x < data.size(); x++) {
        // Create a vector of actions
        vector<action> actionVec;

        // For each action in the line
        for (int y = 1; y < data.getData(x).size(); y++) {
            
            // For each action available check if its the action to assign to the map
            for (int a = 0; a < actions.size(); a++) {
                if (data.getData(x, y) == actions[a].getActionName()) {
                    actionVec.push_back(actions[a]);
                    break;
                }
            }
        }

        // Create the map
        map[data.getData(x, 0)] = actionVec;
    }

    file.closeFile();

}