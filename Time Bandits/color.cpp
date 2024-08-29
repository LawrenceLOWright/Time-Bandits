#include "color.h"

// =================================================
// Sets the current background color and text color for any printed text.
// =================================================

/**
 * @class color
 * @brief A class to manage text and background colors for console output.
 */
 
/**
 * @brief Sets the current text and background colors for console output.
 * 
 * This method updates the console text and background colors based on the provided values.
 * It uses the `SetConsoleTextAttribute` function to apply the color settings.
 * 
 * @param txt The color value for the text.
 * @param bg The color value for the background.
 */
void color::setCurrentColor(int txt, int bg) {
    textColor = txt;
    bgColor = bg;

    // Combine background and text colors and apply them
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

/**
 * @brief Resets the console text color to the default setting.
 * 
 * This method sets the console text color to a default value (usually white text on black background).
 */
void color::setDefault() { 
    SetConsoleTextAttribute(hConsole, 7); 
}
