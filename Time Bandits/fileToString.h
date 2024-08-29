#pragma once
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
class fileToString {
public:
    /**
     * @brief Constructs a fileToString object by loading text and color information from specified files.
     * 
     * The constructor expects three files: one for the text, one for the text color, and one for the background color.
     * It appends the appropriate extensions to the provided base filename to form the full paths.
     * 
     * @param file The base name of the files (without extension).
     */
    fileToString(string file);

    /**
     * @brief Reads the contents of a file and returns it as a single string.
     * 
     * This method opens the specified file, reads its contents line by line, and concatenates them into a single string.
     * 
     * @param filePath The path to the file to be read.
     * @return The contents of the file as a string.
     */
    string getText(string filePath);

    /**
     * @brief Retrieves the text read from the primary file.
     * 
     * @return The text stored in the object.
     */
    string getText();

    /**
     * @brief Converts the stored text into a vector of character objects, with colors applied.
     * 
     * This method processes each character of the text and its corresponding color values to create a vector of
     * `character` objects. Each character's text color and background color are determined by the respective color data.
     * 
     * @return A vector of `character` objects representing the text with applied colors.
     */
    vector<character> textToChar();

private:
    string str; /**< The text read from the file. */
    string txtColor; /**< The text color data. */
    string backgroundColor; /**< The background color data. */
};
