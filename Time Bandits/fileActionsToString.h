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
#include "File.h"

using namespace std;
using namespace std::chrono;

/**
 * @class fileMessagesToString
 * @brief A class to handle reading text from a file and converting it into a vector of message objects.
 */
class fileActionsToString {
    public:
        fileActionsToString(string filename, string filename2);
        vector<action> getActions();
        map<string, vector<action>> getActionMap();
    

    private:
        string filePath;
        string filePath2;
        vector<action> actions = {};
        map<string, vector<action>> map;

        void createActionMap(string filePath2);
        vector<action> getText(string filePath);
};
