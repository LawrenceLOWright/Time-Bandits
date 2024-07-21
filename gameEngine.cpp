#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#define UNICODE
#include <chrono> // Include the chrono header

using namespace std;
using namespace std::chrono; // To avoid typing std::chrono:: every time

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
        std::this_thread::sleep_for(chrono::milliseconds(10));
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

private:
    string fullBox = "█";
    int screenWidth = 120;
    int screenHeight = 40;
    string txt1 = "Dragons have always been a central figure in mythology, legends, and fantasy literature. Among the various species of dr\n";
    string txt3 = "entities that embody the essence of the heavens. They are considered guardians of celestial bodies and cosmic balance. I";
    string txt2 = "and hybrids such as the Solarus dragon stand out for their unique characteristics and lore.Celestial dragons are often d";
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

int main() {
    Screen screen;
    Timer timer;

    // Set the encoding to utf-8
    system("chcp 65001");
    system("echo off");
    
    // Start the timer
    timer.startTimer();
    
    screen.changeScreenSize(120,10);

    // Call refreshScreen multiple times
    //screen.refreshScreen();
    
    // Stop the timer
    timer.stopTimer();
    //timer.returnDuration();

    screen.generateLine();

    
    system("Pause");
}