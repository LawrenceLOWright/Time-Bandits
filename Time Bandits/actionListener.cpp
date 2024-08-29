#include "actionListener.h"

#include <iostream>
#include <windows.h>

using namespace std;

/**
 * @class actionListener
 * @brief A class to handle listening for various types of user input actions.
 */

/**
 * @brief Listens for a single key input from the user and returns the corresponding ASCII character.
 * 
 * This method continuously checks all possible key codes to see if a key is pressed. Once a key is pressed,
 * it converts the key code to its corresponding ASCII character and returns it.
 * 
 * @return The ASCII character corresponding to the key pressed.
 */
char actionListener::singleInputListen() {
    while (true) {
        // Iterate through all possible key codes (0 to 255)
        for (int keyCode = 0; keyCode < 256; ++keyCode) {
            // Check if the key with keyCode is currently pressed
            if (GetAsyncKeyState(keyCode) & 0x8000) {
                // Convert the key code to ASCII character
                char keyChar = static_cast<char>(keyCode);
                return keyChar;
            }
        }
        Sleep(100);
    }
}

/**
 * @brief Listens for a single key input from the user and returns the key code.
 * 
 * This method continuously checks all possible key codes to see if a key is pressed. Once a key is pressed,
 * it returns the key code associated with that key.
 * 
 * @return The integer key code corresponding to the key pressed.
 */
int actionListener::codeInputListener() {
    while (true) {
        // Iterate through all possible key codes (0 to 255)
        for (int keyCode = 0; keyCode < 256; ++keyCode) {
            // Check if the key with keyCode is currently pressed
            if (GetAsyncKeyState(keyCode) & 0x8000) {
                // Return the key code
                return keyCode;
            }
        }
        Sleep(100);
    }
}

/**
 * @brief Listens for a string input from the user.
 * 
 * This method waits for the user to enter a string via standard input and returns the input string.
 * 
 * @return A string entered by the user.
 */
string actionListener::stringInputListener() {
    string input;
    cin >> input;
    return input;
}
