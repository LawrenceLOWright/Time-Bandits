#include "fileAssetsToString.h"

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

fileAssetsToString::fileAssetsToString(string filePath) {
    allAssetsLists = getText(filePath + ".actions");
    cout << filePath + ".actions";
}

map<string, vector<character>> fileAssetsToString::getText(string filePath) {
    fstream file;
    gameTools game;

    file.open(filePath, ios::in);
    if (!file.is_open()) {
        cout << "ERROR HERE";
        error e = error("Cannot find file");
        return allAssetsLists;
    }
    
    string lines = "";
    string tp = "";
    while (getline(file, tp)) {
        stringstream actionDetails(tp);
        string segment2 = "";
        getline(actionDetails, segment2, ',');
        cout << segment2;

        vector<character> currAsset = game.loadAsset(segment2);
        allAssetsLists[segment2] = currAsset;
    }
    
    file.close();
    
    return allAssetsLists;
}
