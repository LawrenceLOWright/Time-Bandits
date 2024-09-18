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

    //cout << "file action to string";

    string lines = "";
    string tp = "";
    int keycode = 1;

    while (getline(file.file, tp)) {
        stringstream actionDetails(tp);

        string actionName = "";
        string activity = "";
        getline(actionDetails, actionName, ',');
        getline(actionDetails, activity, ',');
        
        action a;
        a.setActionDetails(actionName, activity);
        actions.push_back(a);
        keycode++;
    }

    file.closeFile();
    return actions;
};

void fileActionsToString::createActionMap(string filePath2) {
    File file = File(filePath2);
    file.openFile();


    string lines = "";
    string tp = "";
    while (getline(file.file, tp)) {
        vector<action> test;
        stringstream actionDetails(tp);
        string name = "";
        string actionInfo = "";
        getline(actionDetails, name, ',');
        while (getline(actionDetails, actionInfo, ',')) {
            for (int x = 0; x < actions.size(); x++) {
                if (actionInfo == actions[x].getActionName()) {
                    test.push_back(actions[x]);
                    break;
                }
            }
            map[name] = test;
        }

    }
    file.closeFile();

}