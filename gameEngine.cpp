#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> 

#include "Classes\_char.hpp"
#include "Classes\_color.cpp"
#include "Classes\_sprite.cpp"
#include "Classes\fileToString.cpp"
#include "Classes\Timer.cpp"

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

    void loadScreen () {
        _color c;
        c.setCurrentColor(1,1);

        // Load current screen testing
        string s = "";
        for (int y = 0; y <= screenHeight; y++) {
            for (int x = 0; x <= screenWidth; x++) {
                s = s + "1";
            }
        }
        
        cout << s;
        c.setDefault();
        
    }

private:
    string fullBox = "█";
    int screenWidth = 120;
    int screenHeight = 200;
    string txt1 = "Dragons have always been a central figure in mythology, legends, and fantasy literature. Among the various species of dr\n";
    string txt3 = "entities that embody the essence of the heavens. They are considered guardians of celestial bodies and cosmic balance. I";
    string txt2 = "and hybrids such as the Solarus dragon stand out for their unique characteristics and lore.Celestial dragons are often d";
};


// =================================================
// Deals with the game script


// =================================================
class Game {
    public:
    void LoadGame () {
        Screen screen;

        // Set the encoding to utf-8 for cmd
        system("chcp 65001");

        // Set screen size to 120 x by 40 y
        screen.changeScreenSize(150,50);

        // Timer t;

        // t.startTimer();

        screen.loadScreen();
        screen.refreshScreen();
        screen.loadScreen();
        screen.refreshScreen();



        // t.stopTimer();
        // t.returnDuration();
    }
};

// ===============================================================
// MAIN CODE
// ===============================================================

int main() {
    Timer timer;
    Game game;

    //game.LoadGame();

    //system("@echo off");

    _char c;

    fileToString f = fileToString("test.txt");
    vector<_char> scene = f.textToChar();
    cout << f.getText() << endl;
    std::cout << "Vector size: " << scene.size() << std::endl;

    cout << "=======Hello=====" << endl;
    cout << scene[0].getChar(); //nothing but needs 2 be here
    cout << scene[1].getChar(); //emoji
    cout << scene[2].getChar(); //nothing
    cout << scene[3].getChar(); //nothing
    cout << scene[4].getChar(); // B
    cout << scene[5].getChar();
    cout << scene[6].getChar();
    //cout << scene[11].getChar();
    cout << "============" << endl;


    //Character c = Character('e',"Red");
    //c.printChar();
    
    //system("Pause");
}
