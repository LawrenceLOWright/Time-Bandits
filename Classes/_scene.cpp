#include "_scene.hpp"

#define UNICODE

using namespace std;
using namespace std::chrono;

// =================================================
// Deals with individual sprites.

// =================================================


        void _scene::initilizer(string sn, vector<_sprite> sa, _sprite* bgs){
            sceneName = sn;
            sprites = sa;
            backgroundSprite = bgs;
        }

        void _scene::initilizer(string sn, vector<_sprite> sa){
            sceneName = sn;
            sprites = sa;

        }

        void _scene::drawScene(){
            for (size_t i = 0; i < sprites.size(); i++) {
                std::cout << sprites[i].getSpriteString() << std::endl;
            }
        }
