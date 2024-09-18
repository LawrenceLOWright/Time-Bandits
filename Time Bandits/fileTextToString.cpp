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

    string lines = "";
    string tp = "";
    while (getline(file.file, tp)) {
        stringstream actionDetails(tp);
        string segment2 = "";
        getline(actionDetails, segment2, ',');

        fileMessagesToString msgToStr = fileMessagesToString(segment2);
        vector<message> text = msgToStr.getLines();
        allMessageLists[segment2] = text;
    }

    file.closeFile();
    return allMessageLists;
}