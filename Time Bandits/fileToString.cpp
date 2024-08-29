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

/**
 * @class fileToString
 * @brief A class to read text and color data from files and convert them into a vector of character objects.
 */
 
/**
 * @brief Constructs a fileToString object by loading text and color information from specified files.
 * 
 * The constructor expects three files: one for the text, one for the text color, and one for the background color.
 * It appends the appropriate extensions to the provided base filename to form the full paths.
 * 
 * @param file The base name of the files (without extension).
 */
fileToString::fileToString(string file) {
    string filePath = file + ".txt";
    string colorPath = file + ".color";
    string bgColor = file + ".background";

    str = getText(filePath);

    txtColor = getText(colorPath);
    txtColor = txtColor.substr(2); // Assumes first two characters are metadata and should be removed

    backgroundColor = getText(bgColor);
    backgroundColor = backgroundColor.substr(2); // Assumes first two characters are metadata and should be removed
}

/**
 * @brief Reads the contents of a file and returns it as a single string.
 * 
 * This method opens the specified file, reads its contents line by line, and concatenates them into a single string.
 * 
 * @param filePath The path to the file to be read.
 * @return The contents of the file as a string.
 */
string fileToString::getText(string filePath) {
    fstream file;
    file.open(filePath, ios::in);
    if (!file.is_open()) { return ""; } // Return an empty string if the file cannot be opened

    string lines = "";
    string tp = "";
    while (getline(file, tp)) {
        lines += "\n" + tp;
    }

    file.close();
    return lines;
}

/**
 * @brief Retrieves the text read from the file.
 * 
 * @return The text stored in the object.
 */
string fileToString::getText() { return str; }

/**
 * @brief Converts the stored text into a vector of character objects, with colors applied.
 * 
 * This method processes each character of the text and its corresponding color values to create a vector of
 * `character` objects. Each character's text color and background color are determined by the respective color data.
 * 
 * @return A vector of `character` objects representing the text with applied colors.
 */
vector<character> fileToString::textToChar() {
    int length = str.length();
    vector<character> vec;
    vec.reserve(length);

    for (int x = 0; x < length; x++) {
        string c(1, str.at(x));
        string e(1, txtColor.at(x));
        string d(1, backgroundColor.at(x));

        character character;
        character.setChar(c);

        int txt = 0;
        int bg = 0;

        // Map color codes to integers
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
        // cout << vec[x].getChar();
    }
    return vec;
}
