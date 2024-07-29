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
// Deals with loading order of sprites


// =================================================

class zBuffer {
    public:
        void addToBuffer (_sprite toAdd) {
            if (layeredVector.size() == 0)
            {
                layeredVector.push_back(toAdd);
            }
            else {
                int layer = _sprite.getZ();
                for (int i = 0; i < layeredVector.size(); i++) {
                    if(layeredVector[i].getZ() == layer){
                        LayeredVector.insert(i, toAdd);
                    }
                }
                
            }
        }

        vector(_sprite) getLayers() {return layeredVector;}


    private:
        vector(_sprite) layeredVector;
    
}