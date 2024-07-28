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

        setColor (int color) {
            txtColor = color;
            backgroundColor = color;
        }

        setColor (int txt, int background) {
            txtColor = txt;
            backgroundColor = background;
        }

        getBackgroundColor () {return backgroundColor;}
        getTextColor () {return txtColor;}

        getX () {return x;}
        getY () {return y;}
        getZ () {return z;}

        setXYZ (int X, int Y, int Z) {
            x = X;
            y = Y;
            z = Z;
        }

        setChar (string c) {character = c;}
        setChar (boolean toNull) {isNull = toNull;}
        getChar () {return character;}

    private:
    int x = -1;
    int y = -1;
    int z = -1;

    string character = "";
    boolean isNull = false;
    int txtColor = 1;
    int backgroundColor = 15;
};