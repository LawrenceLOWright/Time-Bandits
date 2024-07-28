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
// Deals with individual characters.


// =================================================

class _char {
    public:
        _char (string c) {setChar(c);}

        void setColor (int color) {
            txtColor = color;
            backgroundColor = color;
        }

        void setColor (int txt, int background) {
            txtColor = txt;
            backgroundColor = background;
        }

        int getBackgroundColor () {return backgroundColor;}
        int getTextColor () {return txtColor;}

        int getX () {return x;}
        int getY () {return y;}
        int getZ () {return z;}

        void setXYZ (int X, int Y, int Z) {
            x = X;
            y = Y;
            z = Z;
        }

        void setChar (string c) {character = c;}
        void setChar (boolean toNull) {isNull = toNull;}
        string getChar () {return character;}

    private:
    int x = -1;
    int y = -1;
    int z = -1;

    string character = "";
    boolean isNull = false;
    int txtColor = 1;
    int backgroundColor = 15;
};