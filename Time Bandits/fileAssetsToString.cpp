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
    gameTools game;

    File file = File(filePath);
    file.openFile();

    
    string lines = "";
    string tp = "";
    while (getline(file.file, tp)) {
        stringstream actionDetails(tp);
        string segment2 = "";
        getline(actionDetails, segment2, ',');
        cout << segment2;

        vector<character> currAsset = game.loadAsset(segment2);
        allAssetsLists[segment2] = currAsset;
    }
    
    file.closeFile();
    
    return allAssetsLists;
}
