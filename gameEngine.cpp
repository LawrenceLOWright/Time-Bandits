#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header

#define UNICODE

using namespace std;
using namespace std::chrono; // To avoid typing std::chrono:: every time


// =================================================
// Used for timing frames and functions.


// =================================================

class txtToString {
    public:
        string content; 

        txtToString(const string& filePath) {
            ifstream file(filePath);
            if (!file.is_open()) {return;}

            string line;
            while (getline(file, line)) {
                content += line + "\0"; 
            }
            file.close();
        }

        string getContent() const {
            return content;
        }
};

class Timer {
    public:
        Timer() : start(high_resolution_clock::now()), stop(high_resolution_clock::now()) {}

        void startTimer() {start = high_resolution_clock::now();}

        void stopTimer() {stop = high_resolution_clock::now();}

        void returnDuration() {
            auto duration = duration_cast<milliseconds>(stop - start);
            cout << "Time taken: " << duration.count() << " milliseconds" << endl;
        }

    private:
        time_point<high_resolution_clock> start;
        time_point<high_resolution_clock> stop;
};


// =================================================
// Deals with the sprite characters


// =================================================
class Sprite {
    public:
    int x = 0;
    int y = 0;
    string test = "XXXX\n" \
    "cccc";

    // To-do using character class
    void strToCharArray () {
        
    }
};

// =================================================
// Deals with individual characters.


// =================================================

class Character {
    public:
    string character;
    int txtColor = 1;
    int backgroundColor = 1;

    Character (string cha, int col, int back) {
        character = cha;
        txtColor = col;
        backgroundColor = back;
    }
};


// =================================================
// Sets the current background color and text color for any printed text.


// =================================================
class ColorLine {
    public:
    void setCurrentColor (int txt, int bg) {
        textColor = txt;
        bgColor = bg;

        SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
    }

    void setDefault () {SetConsoleTextAttribute(hConsole, 7);}

    private:
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int textColor = 1;
    int bgColor = 1;
};

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
        ColorLine c;
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

        Sprite s;
        cout << s.test;


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

    game.LoadGame();

    system("@echo off");



    //Character c = Character('e',"Red");
    //c.printChar();
    
    //system("Pause");
}