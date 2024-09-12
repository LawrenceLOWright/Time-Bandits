
#include "loadGame.h"

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header
#include <vector>
#include <map>
#include <sstream>



loadGame::loadGame() {
    // Set the encoding
    string str = retrieveSetting("Encoding");
    const char* cstr = str.c_str();
    system(cstr);

    // Set Game Screen Size
    gameTools game;
    std::stringstream ss(retrieveSetting("ScreenWidth"));
    std::stringstream ss2(retrieveSetting("ScreenHeight"));
    int num, num2;
    ss >> num;
    ss2 >> num2;
    game.changeScreenSize(num, num2);

    //std::string tp = retrieveSetting("ScreenHeight");
    //std::string command = "msg %username% 1" + tp;

    // Execute the command using Boost.Process
    //system(command.c_str());

}

string loadGame::retrieveSetting(string settingName) {
    fstream file;
    string filePath = "settings.info";
    file.open(filePath, ios::in);
    if (!file.is_open()) { error er = error("File is missing"); }


    string lines = "";
    string tp = "";
    int num = 1;
    while (getline(file, tp)) {
        stringstream details(tp);
        string segment1 = "";

        
        while (getline(details, segment1, ',')) {
            
            if (settingName == segment1) {
                getline(details, segment1, ',');
                
                return segment1;
                break;
            }
        }
        
    }


    file.close();

    return "Nothing";

}

