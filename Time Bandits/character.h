#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header

//#define UNICODE

using namespace std;
using namespace std::chrono;

/**
 * @class character
 * @brief A class to represent and manage individual characters with their attributes.
 */
class character {
public:
    /**
     * @brief Sets both the text and background color of the character to the same value.
     * 
     * @param color The color value to set for both text and background.
     */
    void setColor(int color);

    /**
     * @brief Sets the text and background colors of the character separately.
     * 
     * @param txt The color value for the text.
     * @param background The color value for the background.
     */
    void setColor(int txt, int background);

    /**
     * @brief Retrieves the background color of the character.
     * 
     * @return The integer value representing the background color.
     */
    int getBackgroundColor();

    /**
     * @brief Retrieves the text color of the character.
     * 
     * @return The integer value representing the text color.
     */
    int getTextColor();

    /**
     * @brief Retrieves the X coordinate of the character.
     * 
     * @return The integer value representing the X coordinate.
     */
    int getX();

    /**
     * @brief Retrieves the Y coordinate of the character.
     * 
     * @return The integer value representing the Y coordinate.
     */
    int getY();

    /**
     * @brief Retrieves the Z coordinate of the character.
     * 
     * @return The integer value representing the Z coordinate.
     */
    int getZ();

    /**
     * @brief Sets the X, Y, and Z coordinates of the character.
     * 
     * @param X The X coordinate value.
     * @param Y The Y coordinate value.
     * @param Z The Z coordinate value.
     */
    void setXYZ(int X, int Y, int Z);

    /**
     * @brief Sets the character's string representation.
     * 
     * @param c The string to set as the character representation.
     */
    void setChar(string c);

    /**
     * @brief Sets whether the character is considered null.
     * 
     * @param toNull A boolean value indicating if the character is null.
     */
    void setCharNull(bool toNull);

    /**
     * @brief Retrieves the string representation of the character.
     * 
     * @return A string representing the character.
     */
    string getChar();

private:
    int x; /**< The X coordinate of the character. */
    int y; /**< The Y coordinate of the character. */
    int z; /**< The Z coordinate of the character. */

    string charact; /**< The string representation of the character. */
    bool isNull; /**< Indicates whether the character is null. */
    int txtColor; /**< The text color of the character. */
    int backgroundColor; /**< The background color of the character. */
};
