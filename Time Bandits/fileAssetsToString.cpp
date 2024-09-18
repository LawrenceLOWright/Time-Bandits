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

    FileRetrival data = FileRetrival(file);

    for (int x = 0; x < data.size(); x++) {
        vector<character> currAsset = game.loadAsset(data.getData(x, 0));
        allAssetsLists[data.getData(x, 0)] = currAsset;
    }
    
    file.closeFile();
    
    return allAssetsLists;
}
