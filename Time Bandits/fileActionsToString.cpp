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
    fstream file;
    file.open(filePath, ios::in);
    if (!file.is_open()) {
        cout << "HERE55";
        return actions;
    }


    string lines = "";
    string tp = "";
    while (getline(file, tp)) {
        stringstream actionDetails(tp);
        string segment2 = "";
        string segment3 = "";
        string segment4 = "";
        getline(actionDetails, segment2, ',');
        getline(actionDetails, segment3, ',');
        getline(actionDetails, segment4, ',');
        action a;
        a.setActionDetails(segment2, segment3, stoi(segment4));
        actions.push_back(a);
    }

    file.close();
    return actions;
};

void fileActionsToString::createActionMap(string filePath2) {
    fstream file;
    file.open(filePath2, ios::in);
    if (!file.is_open()) {
        cout << "HERE23";
    }


    string lines = "";
    string tp = "";
    while (getline(file, tp)) {
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

}