#include "fileTextToString.h"

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
 * @brief Constructs a fileTextToString object and retrieves all messages from the specified file.
 * 
 * @param filePath The path to the file (without extension) containing the message data.
 */
fileTextToString::fileTextToString(string filePath) {
    allMessageLists = getText(filePath + ".actions"); 
}

/**
 * @brief Retrieves message data from the file and populates the message map.
 * 
 * @param filePath The path to the file to read the message data from.
 * @return A map containing message lists, with the key being the message identifier.
 */
map<string, vector<message>> fileTextToString::getText(string filePath) {
    File file = File(filePath);
    file.openFile();

    FileRetrival data = FileRetrival(file);
    
    for (int x = 0; x < data.size(); x++) {
        fileMessagesToString msgToStr = fileMessagesToString(data.getData(x, 0));
        vector<message> lines = msgToStr.getLines();
        allMessageLists[data.getData(x, 0)] = lines;
    }

    file.closeFile();
    return allMessageLists;
}
