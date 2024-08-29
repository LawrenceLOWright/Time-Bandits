#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header

using namespace std;
using namespace std::chrono;

// =================================================
// Sets the current background color and text color for any printed text.
// =================================================

/**
 * @class color
 * @brief A class to manage text and background colors for console output.
 */
class color {
public:
    /**
     * @brief Sets the current text and background colors for console output.
     * 
     * This method updates the console text and background colors based on the provided values.
     * It uses the `SetConsoleTextAttribute` function to apply the color settings.
     * 
     * @param txt The color value for the text.
     * @param bg The color value for the background.
     */
    void setCurrentColor(int txt, int bg);

    /**
     * @brief Resets the console text color to the default setting.
     * 
     * This method sets the console text color to a default value (usually white text on black background).
     */
    void setDefault();

private:
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); /**< Handle to the console output. */
    int textColor = 1; /**< The current text color (default is blue). */
    int bgColor = 1; /**< The current background color (default is blue). */
};
