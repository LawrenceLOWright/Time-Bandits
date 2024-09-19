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
#include "message.h"
#include "File.h"

using namespace std;
using namespace std::chrono;

/**
 * @class fileMessagesToString
 * @brief A class to handle reading text from a file and converting it into a vector of message objects.
 */
class fileMessagesToString {
public:
    /**
     * @brief Constructs a fileMessagesToString object by loading text from a specified file.
     * 
     * The file is expected to have a `.text` extension, which is appended to the provided filename.
     * 
     * @param file The base name of the file (without extension).
     */
    fileMessagesToString(string file);

    /**
     * @brief Retrieves the vector of message objects representing the lines of text from the file.
     *                                              
     * @return A vector of message objects.
     */
    vector<message> getLines();

private:
    /**
     * @brief Reads text from a specified file and splits it into message objects.
     * 
     * This method opens the specified file and reads its contents line by line. Each line is split into segments
     * of up to 85 characters (breaking at spaces when possible) and stored in a message object. The resulting
     * message objects are collected into a vector and returned.
     * 
     * @param filePath The path to the file to be read.
     * @return A vector of message objects created from the file's text.
     */
    vector<message> getText(string filePath);

    vector<message> str; /**< A vector of message objects representing the lines of text from the file. */
};
