#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> 
#include <vector>
#include "_char.hpp"

#define UNICODE

using namespace std;
using namespace std::chrono;

// =================================================
// Deals with the sprite characters


// =================================================
class _sprite {
    public:
        _sprite (string sp, string name) {
            sprite = sp;
            setSpriteName(name);
        }

        void setX (int X) {x = X;}
        void setY (int Y) {y = Y;}
        void setZ (int Z) {z = Z;}
        void setXYZ (int X, int Y, int Z) {
            x = X;
            y = Y;
            z = Z;
        }

        int getX () {return x;}
        int getY () {return y;}
        int getZ () {return z;}

        string getSpriteString () {return sprite;}

        void setSpriteName (string name) {spriteName = name;}
        string getSpriteName () {return spriteName;}
    
    private:
        int x = -1;
        int y = -1;
        int z = -1;

        string sprite;
        string spriteName = "";
};