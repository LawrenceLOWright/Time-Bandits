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
// Deals with individual sprites.
//----------variables-------------
//sceneName
//spritesArray
//backgroundSprite
//-----------methods--------------
//initilizer : sets a sprites array, backgroundSprite and sceneName
//drawScene : draws the scene to the screen.
//--------------------------------
// =================================================

class _scene {
    public:
        void initilizer(string sn, vector(_sprite) sa, _sprite bgs){
            sceneName = sn;
            spriteArray = sa;
            backgroundSprite = bgs;
        }

        void drawScene(){
            
        }

    private:
        string sceneName;
        vector(_sprite) spriteArray;
        _sprite backgroundSprite;

    
}