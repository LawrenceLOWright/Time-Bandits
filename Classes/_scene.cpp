#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> 
#include <vector>
#include "_sprite.cpp"
#include "_char.hpp"

#define UNICODE

using namespace std;
using namespace std::chrono;

// =================================================
// Deals with individual sprites.

// =================================================

class _scene {
    public:
        void initilizer(string sn, vector<_sprite> sa, _sprite bgs){
            sceneName = sn;
            sprites = sa;
            backgroundSprite = bgs;
        }

        void initilizer(string sn, vector<_sprite> sa){
            sceneName = sn;
            sprites = sa;
        }

        void drawScene(){
            for (size_t i = 0; i < sprites.size(); i++)
            {
                std::cout << sprites[i].getSpriteString() << std::endl;
            }
            
        }

    private:
        string sceneName;
        std::vector<_sprite> sprites;
        _sprite backgroundSprite;

    
};