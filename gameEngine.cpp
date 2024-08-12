#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> 

#include "Classes\_char.hpp"
#include "Classes\_color.cpp"
#include "Classes\_sprite.hpp"
#include "Classes\fileToString.cpp"
#include "Classes\Timer.cpp"
#include "Classes\_scene.hpp"

#define UNICODE

using namespace std;
using namespace std::chrono; // To avoid typing std::chrono:: every time





// =================================================
// Deals with code relating to the screen


// =================================================

class Screen {
public:
    // Refresh the screen to a new frame.
    void refreshScreen() {
        // 12.33 milliseconds
        //std::string command = "mode con: cols=" + std::to_string(screenWidth) + " lines=" + std::to_string(screenHeight);
        //system(command.c_str());
        system("cls");
        // Print text here
        //cout << txt1;
        //cout.flush();
        //std::this_thread::sleep_for(chrono::milliseconds(10));
    }

    void changeScreenSize (int width, int height) {
        screenWidth = width;
        screenHeight = height;

        std::string command = "mode con: cols=" + std::to_string(screenWidth) + " lines=" + std::to_string(screenHeight);
        system(command.c_str());

    }

    vector<_char> loadAsset (string fileName) {
        fileToString f = fileToString(fileName);
        std::vector<_char> vec = f.textToChar();
        return vec;
    }

    void loadScreen (vector<_char> vec) {
        refreshScreen();
        
        _color color;

        // Must be kept in main code
        int prevCol2 = 999;
        int prevCol = 999;

        for (int x = 0; x < vec.size(); x++) {
            int col2 = vec[x].getBackgroundColor();
            int col = vec[x].getTextColor();
            if (col == prevCol && col2 == prevCol2) {prevCol = col;}
            else {
                prevCol = col;
                prevCol2 = col2;
                color.setCurrentColor(col,col2);
            }
            
            cout << vec[x].getChar();
        }

        color.setDefault();
    }

private:
    string fullBox = "█";
    int screenWidth = 120;
    int screenHeight = 200;
};


// =================================================
// Deals with the game script


// =================================================
class Game {
    public:
    void LoadGame () {
        Screen screen;
        Timer t;

        // Set the encoding to utf-8 for cmd
        system("chcp 65001");

        // Set screen size to 120 x by 40 y
        screen.changeScreenSize(150,50);

        vector<_char> test = screen.loadAsset("test");
        screen.loadScreen(test);
        screen.loadScreen(test);
        screen.loadScreen(test);



        // t.stopTimer();
        // t.returnDuration();
    }
};

// ===============================================================
// MAIN CODE
// ===============================================================

int main() {
    
    Game game;
    _color c;

    game.LoadGame();
    c.setDefault();

    

    system("@echo off");
}

