#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> 
#include <vector>
#include "_sprite.hpp"
#include "_char.hpp"


#define UNICODE

using namespace std;
using namespace std::chrono;

// =================================================
// Deals with individual sprites.

// =================================================

class _scene {
    public:
        void initilizer(string sn, vector<_sprite> sa, _sprite* bgs);

        void initilizer(string sn, vector<_sprite> sa);

        void drawScene();

    private:
        string sceneName;
        std::vector<_sprite> sprites;
        _sprite* backgroundSprite;
};