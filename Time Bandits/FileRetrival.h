#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono>
#include <vector>
#include <sstream>
#include <map>

#include "character.h"
#include "File.h"

using namespace std;
using namespace std::chrono;

/**
 * @class FileRetrival
 * @brief Handles the retrieval of data from a file and stores it in a map for quick access.
 */
class FileRetrival {
public:
    /**
     * @brief Constructs the FileRetrival object and loads file data into memory.
     * 
     * @param file A reference to a File object that contains the data.
     */
    FileRetrival(File& file);

    /**
     * @brief Retrieves data from a specific file and line position.
     * 
     * @param filePos The position in the file to retrieve data from.
     * @param linePos The line position within the file data to retrieve.
     * @return A string containing the data at the specified file and line position.
     */
    string getData(int filePos, int linePos);

    /**
     * @brief Returns the number of files or data blocks stored.
     * 
     * @return The size of the data map.
     */
    int size();

    /**
     * @brief Retrieves all the data from a specific file position.
     * 
     * @param filePos The position in the file to retrieve all data from.
     * @return A vector of strings containing the data from the specified file position.
     */
    vector<string> getData(int filePos);

private:
    map<int, vector<string>> data; /**< Stores the file data with file position as the key. */
};
