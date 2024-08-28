#include "character.h"


using namespace std;
using namespace std::chrono;

// =================================================
// Deals with individual characters.


// =================================================

void character::setColor(int color) {
    txtColor = color;
    backgroundColor = color;
}

void character::setColor(int txt, int background) {
    txtColor = txt;
    backgroundColor = background;
}

int character::getBackgroundColor() { return backgroundColor; }
int character::getTextColor() { return txtColor; }

int character::getX() { return x; }
int character::getY() { return y; }
int character::getZ() { return z; }

void character::setXYZ(int X, int Y, int Z) {
    x = X;
    y = Y;
    z = Z;
}

void character::setChar(string c) { charact = c; }
void character::setCharNull(bool toNull) { isNull = toNull; }
string character::getChar() { return charact; }
