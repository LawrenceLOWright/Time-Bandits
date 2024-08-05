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
        fileToString(string filePath) {getText(filePath);}

        string getText (string filePath) {
            fstream file;
            file.open(filePath,ios::in);
            if (!file.is_open()) {return NULL;}

            string lines = "";
            string tp = "";
            while(getline(file, tp)){ 
                lines = lines + "\n" + tp; 
            }
            str = lines;
            file.close();
            return str;
        }

        string getText () {return str;}

        // vector<_char>
        /*
        void textToChar () {
            string nullChar = "😎";
            int length = str.length();
            std::vector<_char> vec;
            vec.reserve(length); 

            // Convert each char into a _char array
            for (int x = 0; x < length; x++) {
                string c(1, str.at(x));
                _char character;
                if (c == nullChar) {character.setChar(true);} 
                else {character.setChar(c);}
                vec.push_back(character);
                
            }
        }
        */


    private:
        string str;


};
