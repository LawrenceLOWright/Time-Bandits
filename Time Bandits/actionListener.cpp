#include "actionListener.h"

#include <iostream>
#include <windows.h>


using namespace std;
//using namespace std::chrono;


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

int actionListener::codeInputListener() {
    while (true) {
        // Iterate through all possible key codes (0 to 255)
        for (int keyCode = 0; keyCode < 256; ++keyCode) {
            // Check if the key with keyCode is currently pressed
            if (GetAsyncKeyState(keyCode) & 0x8000) {
                // Convert the key code to ASCII character

                return keyCode;
            }
        }
        Sleep(100);
    }
}

string actionListener::stringInputListener() {
    string input;
    cin >> input;
    return input;
}
