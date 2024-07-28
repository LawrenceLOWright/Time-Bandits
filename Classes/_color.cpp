#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header


#define UNICODE

using namespace std;
using namespace std::chrono;

// =================================================
// Sets the current background color and text color for any printed text.


// =================================================

class _color {
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