#pragma once
#include <iostream>
#include <windows.h>

using namespace std;
//using namespace std::chrono;

/**
 * @class actionListener
 * @brief A class to handle listening for various types of user input actions.
 */
class actionListener {
public:
    /**
     * @brief Listens for a single key input from the user and returns the corresponding ASCII character.
     * 
     * This method continuously checks all possible key codes to see if a key is pressed. Once a key is pressed,
     * it converts the key code to its corresponding ASCII character and returns it.
     * 
     * @return The ASCII character corresponding to the key pressed.
     */
    char singleInputListen();

    /**
     * @brief Listens for a single key input from the user and returns the key code.
     * 
     * This method continuously checks all possible key codes to see if a key is pressed. Once a key is pressed,
     * it returns the key code associated with that key.
     * 
     * @return The integer key code corresponding to the key pressed.
     */
    int codeInputListener();

    /**
     * @brief Listens for a string input from the user.
     * 
     * This method waits for the user to enter a string via standard input and returns the input string.
     * 
     * @return A string entered by the user.
     */
    string stringInputListener();
};
