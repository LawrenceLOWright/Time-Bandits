#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header
#include <vector>
#include "_char.hpp"

#define UNICODE

using namespace std;
using namespace std::chrono;


class fileToString {
    public:
        fileToString(string filePath, string colorPath) {
            str = getText(filePath);
            colors = getText(colorPath);
            colors = colors.substr(2);
        }

        string getText (string filePath) {
            fstream file;
            file.open(filePath,ios::in);
            if (!file.is_open()) {return NULL;}

            string lines = "";
            string tp = "";
            int lineNum = 0;
            while(getline(file, tp)){ 
                lines = lines + "\n" + tp; 
            }

            file.close();
            return lines;
        }

        string getText () {return str;}

        // vector<_char>
        
        vector<_char> textToChar () {
            string nullChar = "😎";
            int length = str.length();
            std::vector<_char> vec;
            vec.reserve(length); 

            // Convert each char into a _char array
            for (int x = 0; x < length; x++) {
                string c(1, str.at(x));
                string e(1, colors.at(x));

                _char character;
                if (c == nullChar) {character.setCharNull(true);} 
                else {character.setChar(c);}

                if (e == "b") {
                    character.setColor(9);
                }


                vec.push_back(character);
                // Print to screen (testing)
                //cout << vec[x].getChar();

                
            }
            return vec;
        }
        


    private:
        string str;
        string colors;

};

