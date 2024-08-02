
#include "_char.hpp" // Include the chrono header


#define UNICODE

using namespace std;
using namespace std::chrono;

// =================================================
// Deals with individual characters.


// =================================================

        void _char::setColor (int color) {
            txtColor = color;
            backgroundColor = color;
        }

        void _char::setColor (int txt, int background) {
            txtColor = txt;
            backgroundColor = background;
        }

        int _char::getBackgroundColor () {return backgroundColor;}
        int _char::getTextColor () {return txtColor;}

        int _char::getX () {return x;}
        int _char::getY () {return y;}
        int _char::getZ () {return z;}

        void _char::setXYZ (int X, int Y, int Z) {
            x = X;
            y = Y;
            z = Z;
        }

        void _char::setChar (string c) {character = c;}
        void _char::setCharNull (bool toNull) {isNull = toNull;}
        string _char::getChar () {return character;}
