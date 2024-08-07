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

        void getText (string filePath) {
            fstream file;
            file.open(filePath,ios::in);
            if (!file.is_open()) {return;}

            string lines = "";
            string tp = "";
            int lineNum = 0;
            while(getline(file, tp)){ 
                if (lineNum == 0) {lines = lines + tp;} 
                else {lines = lines + "}" + tp;}
            }
            str = lines;
            file.close();
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
                _char character;
                if (c == nullChar) {character.setCharNull(true);} 
                else {character.setChar(c);}
                vec.push_back(character);
                cout << vec[x].getChar();
                
            }

            

            return vec;
        }



    private:
        string str;


};
