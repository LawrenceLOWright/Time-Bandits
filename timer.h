#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header



using namespace std;
using namespace std::chrono;


// =================================================
// Used for timing frames and functions.


// =================================================

class timer {
public:
    timer();

    void startTimer();

    void stopTimer();

    void returnDuration();

private:
    time_point<high_resolution_clock> start;
    time_point<high_resolution_clock> stop;
};