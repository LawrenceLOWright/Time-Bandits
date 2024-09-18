#include "fileTextToString.h"

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

fileTextToString::fileTextToString(string filePath) {
    allMessageLists = getText(filePath + ".actions"); 
}

map<string, vector<message>> fileTextToString::getText(string filePath) {
    File file = File(filePath);
    file.openFile();

    FileRetrival data = FileRetrival(file);
    for (int x = 0; x < data.size(); x++) {
        fileMessagesToString msgToStr = fileMessagesToString(data.getData(x,0));
        vector<message> lines = msgToStr.getLines();
        allMessageLists[data.getData(x, 0)] = lines;
    }

    file.closeFile();
    return allMessageLists;
}