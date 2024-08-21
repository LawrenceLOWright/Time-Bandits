#include <iostream>
#include <windows.h>
#include "_actionListener.hpp"


#define UNICODE

using namespace std;
using namespace std::chrono;


        char _actionListener::singleInputListen(){
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

        int _actionListener::codeInputListener(){
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

        string _actionListener::stringInputListener(){
            string input;
            cin>>input;
            return input;
        }
