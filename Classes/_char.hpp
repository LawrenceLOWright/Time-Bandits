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

        void setColor (int color);
        void setColor (int txt, int background);


        int getBackgroundColor ();
        int getTextColor ();

        int getX ();
        int getY ();
        int getZ ();

        void setXYZ (int X, int Y, int Z);

        void setChar (string);
        void setCharNull (bool);
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
