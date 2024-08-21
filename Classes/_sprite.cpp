#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> 
#include <vector>
#include "_char.hpp"
#include "_sprite.hpp"

#define UNICODE

using namespace std;
using namespace std::chrono;

// =================================================
// Deals with the sprite characters


// =================================================

        void _sprite::initilizer (string sp, string name) {
            sprite = sp;
            setSpriteName(name);
        }

        void _sprite::setX (int X) {x = X;}
        void _sprite::setY (int Y) {y = Y;}
        void _sprite::setZ (int Z) {z = Z;}
        void _sprite::setXYZ (int X, int Y, int Z) {
            x = X;
            y = Y;
            z = Z;
        }

        int _sprite::getX () {return x;}
        int _sprite::getY () {return y;}
        int _sprite::getZ () {return z;}

        string _sprite::getSpriteString () {return sprite;}

        void _sprite::setSpriteName (string name) {spriteName = name;}
        string _sprite::getSpriteName () {return spriteName;}
