#include "character.h"

using namespace std;
using namespace std::chrono;

// =================================================
// Deals with individual characters.
// =================================================

/**
 * @class character
 * @brief A class to represent and manage individual characters with their attributes.
 */

/**
 * @brief Sets both the text and background color of the character.
 * 
 * @param color The color value to set for both text and background.
 */
void character::setColor(int color) {
    txtColor = color;
    backgroundColor = color;
}

/**
 * @brief Sets the text and background colors of the character separately.
 * 
 * @param txt The color value for the text.
 * @param background The color value for the background.
 */
void character::setColor(int txt, int background) {
    txtColor = txt;
    backgroundColor = background;
}

/**
 * @brief Retrieves the background color of the character.
 * 
 * @return The integer value representing the background color.
 */
int character::getBackgroundColor() { return backgroundColor; }

/**
 * @brief Retrieves the text color of the character.
 * 
 * @return The integer value representing the text color.
 */
int character::getTextColor() { return txtColor; }

/**
 * @brief Retrieves the X coordinate of the character.
 * 
 * @return The integer value representing the X coordinate.
 */
int character::getX() { return x; }

/**
 * @brief Retrieves the Y coordinate of the character.
 * 
 * @return The integer value representing the Y coordinate.
 */
int character::getY() { return y; }

/**
 * @brief Retrieves the Z coordinate of the character.
 * 
 * @return The integer value representing the Z coordinate.
 */
int character::getZ() { return z; }

/**
 * @brief Sets the X, Y, and Z coordinates of the character.
 * 
 * @param X The X coordinate value.
 * @param Y The Y coordinate value.
 * @param Z The Z coordinate value.
 */
void character::setXYZ(int X, int Y, int Z) {
    x = X;
    y = Y;
    z = Z;
}

/**
 * @brief Sets the character's string representation.
 * 
 * @param c The string to set as the character representation.
 */
void character::setChar(string c) { charact = c; }

/**
 * @brief Sets whether the character is considered null.
 * 
 * @param toNull A boolean value indicating if the character is null.
 */
void character::setCharNull(bool toNull) { isNull = toNull; }

/**
 * @brief Retrieves the string representation of the character.
 * 
 * @return A string representing the character.
 */
string character::getChar() { return charact; }
