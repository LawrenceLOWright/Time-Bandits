#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header
#include <vector>
#include <map>
#include "character.h"
#include "action.h"
#include "error.h"
#include "gameTools.h"
#include "File.h"

using namespace std;
using namespace std::chrono;

/**
 * @class fileMessagesToString
 * @brief A class to handle reading text from a file and converting it into a vector of message objects.
 */
class fileAssetsToString {
public:
    fileAssetsToString(string filename);
    map<string, vector<character>> allAssetsLists = {};


private:
    string filePath;
    map<string, vector<character>> getText(string filePath);

};