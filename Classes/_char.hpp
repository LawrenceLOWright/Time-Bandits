#pragma once

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

class _char {
    public:

        void setColor ();


        int getBackgroundColor ();
        int getTextColor ();

        int getX ();
        int getY ();
        int getZ ();

        void setXYZ ();

        void setChar (const std::string&);
        void setChar (boolean);
        string getChar ();

    private:
    int x;
    int y;
    int z;

    string character;
    boolean isNull;
    int txtColor;
    int backgroundColor;
};
