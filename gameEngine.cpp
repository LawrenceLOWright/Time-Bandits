#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <chrono> // Include the chrono header

#define UNICODE

using namespace std;
using namespace std::chrono; // To avoid typing std::chrono:: every time



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

class Sprite {
    public:
    int x = 0;
    int y = 0;
};

class Character {
    public:
    string character;
    string color = "White";
    string background = "White";

    Character (string cha, string col, string back) {
        character = cha;
        color = col;
        background = back;
    }

    Character (string cha, string col) {
        character = cha;
        color = col;
        background = col;
    }

    void printChar () {
        std::string command = "powershell -command Write-Host '" + character + "' -ForegroundColor " + color + " -BackgroundColor " + background + " -NoNewline";
        system(command.c_str());
    }
};

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

    void generateLine () {
        cout << "█";
        cout.flush();
    }

    void loadScreen () {
        
        // Load current screen testing
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        string s = "";
        for (int y = 0; y <= screenHeight; y++) {
            for (int x = 0; x <= screenWidth; x++) {

                

                // Print the character
                s = s + "1";

                // Reset the text color to default
                //SetConsoleTextAttribute(hConsole, 7);
            }
            
        }

        // Set the text color
        int textColor = 1;
        int bgColor = 1;
        SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
        cout << s;
        SetConsoleTextAttribute(hConsole, 7);
        
    }

private:
    string fullBox = "█";
    int screenWidth = 120;
    int screenHeight = 200;
    string txt1 = "Dragons have always been a central figure in mythology, legends, and fantasy literature. Among the various species of dr\n";
    string txt3 = "entities that embody the essence of the heavens. They are considered guardians of celestial bodies and cosmic balance. I";
    string txt2 = "and hybrids such as the Solarus dragon stand out for their unique characteristics and lore.Celestial dragons are often d";
};

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

        // t.stopTimer();
        // t.returnDuration();
    }
};

int main() {
    Timer timer;
    Game game;

    game.LoadGame();

    system("@echo off");

    //Character c = Character('e',"Red");
    //c.printChar();
    
    //system("Pause");
}