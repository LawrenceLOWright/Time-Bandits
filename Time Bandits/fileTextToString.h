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
#include "fileMessagesToString.h"
#include "error.h"

using namespace std;
using namespace std::chrono;

/**
 * @class fileMessagesToString
 * @brief A class to handle reading text from a file and converting it into a vector of message objects.
 */
class fileTextToString {
public:
    fileTextToString(string filename);
    map<string, vector<message>> allMessageLists = {};


private:
    string filePath;
    map<string, vector<message>> getText(string filePath);
    
};