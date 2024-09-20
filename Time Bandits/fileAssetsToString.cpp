#include "fileAssetsToString.h"

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> 
#include <vector>
#include <sstream>
#include "character.h"

using namespace std;
using namespace std::chrono;

/**
 * @brief Constructs a fileAssetsToString object and loads asset data from the provided file.
 * 
 * @param filePath The base file path from which to load asset data.
 */
fileAssetsToString::fileAssetsToString(const string filePath) {
    allAssetsLists = getText(filePath + ".actions");
    cout << filePath + ".actions";
}

/**
 * @brief Retrieves asset data from the specified file path and stores it in a map.
 * 
 * @param filePath The file path to retrieve asset data from.
 * @return A map containing asset names as keys and vectors of characters as values.
 */
map<string, vector<character>> fileAssetsToString::getText(string filePath) {
    gameTools game;

    File file = File(filePath);
    file.openFile();

    FileRetrival data = FileRetrival(file);

    // Load each asset from the file and store it in the map
    for (int x = 0; x < data.size(); x++) {
        vector<character> currAsset = game.loadAsset(data.getData(x, 0));
        allAssetsLists[data.getData(x, 0)] = currAsset;
    }

    file.closeFile();

    return allAssetsLists;
}
