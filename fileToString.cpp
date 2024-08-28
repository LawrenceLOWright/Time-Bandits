#include "fileToString.h"

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header
#include <vector>
#include "character.h"


using namespace std;
using namespace std::chrono;



    fileToString::fileToString(string file) {
        string filePath = file + ".txt";
        string colorPath = file + ".color";
        string bgColor = file + ".background";

        str = getText(filePath);

        txtColor = getText(colorPath);
        txtColor = txtColor.substr(2);

        backgroundColor = getText(bgColor);
        backgroundColor = backgroundColor.substr(2);
    }

    string fileToString::getText(string filePath) {
        fstream file;
        file.open(filePath, ios::in);
        if (!file.is_open()) { return NULL; }

        string lines = "";
        string tp = "";
        int lineNum = 0;
        while (getline(file, tp)) {
            lines = lines + "\n" + tp;
        }

        file.close();
        return lines;
    }

    string fileToString::getText() { return str; }

    // vector<_char>

    vector<character> fileToString::textToChar() {
        //string nullChar = "😎";
        int length = str.length();
        std::vector<character> vec;
        vec.reserve(length);

        // Convert each char into a _char array
        for (int x = 0; x < length; x++) {
            string c(1, str.at(x));
            string e(1, txtColor.at(x));
            string d(1, backgroundColor.at(x));

            character character;
            character.setChar(c);

            int txt = 0;
            int bg = 0;

            if (e == "0") { txt = 0; }
            if (e == "1") { txt = 1; }
            if (e == "2") { txt = 2; }
            if (e == "3") { txt = 3; }
            if (e == "4") { txt = 4; }
            if (e == "5") { txt = 5; }
            if (e == "6") { txt = 6; }
            if (e == "7") { txt = 7; }
            if (e == "8") { txt = 8; }
            if (e == "b") { txt = 9; }
            if (e == "g") { txt = 10; }
            if (e == "c") { txt = 11; }
            if (e == "r") { txt = 12; }
            if (e == "m") { txt = 13; }
            if (e == "y") { txt = 14; }
            if (e == "w") { txt = 15; }

            if (d == "0") { bg = 0; }
            if (d == "1") { bg = 1; }
            if (d == "2") { bg = 2; }
            if (d == "3") { bg = 3; }
            if (d == "4") { bg = 4; }
            if (d == "5") { bg = 5; }
            if (d == "6") { bg = 6; }
            if (d == "7") { bg = 7; }
            if (d == "8") { bg = 8; }
            if (d == "b") { bg = 9; }
            if (d == "g") { bg = 10; }
            if (d == "c") { bg = 11; }
            if (d == "r") { bg = 12; }
            if (d == "m") { bg = 13; }
            if (d == "y") { bg = 14; }
            if (d == "w") { bg = 15; }


            character.setColor(txt, bg);

            vec.push_back(character);

            // Print to screen (testing)
            //cout << vec[x].getChar();
        }
        return vec;
    }


