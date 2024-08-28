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
// Sets the current background color and text color for any printed text.


// =================================================

class color {
public:
    void setCurrentColor(int txt, int bg);

    void setDefault();

private:
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int textColor = 1;
    int bgColor = 1;
};