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
        void initilizer (string sp, string name);

        void setX (int X);
        void setY (int Y);
        void setZ (int Z);
        void setXYZ (int X, int Y, int Z);

        int getX ();
        int getY ();
        int getZ ();

        string getSpriteString ();

        void setSpriteName (string name);
        string getSpriteName ();
    
    private:
        int x = -1;
        int y = -1;
        int z = -1;

        string sprite;
        string spriteName = "";
};