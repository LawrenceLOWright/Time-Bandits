#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono>
#include <vector>
#include <map>
#include "character.h"
#include "action.h"
#include "error.h"
#include <sstream>

using namespace std;
using namespace std::chrono;

/**
 * @brief A class to handle file operations such as opening and closing files.
 */
class File {
    public:
        /**
         * @brief Constructs a File object with the given file name.
         * 
         * @param fileName The name of the file to be opened.
         */
        File(string fileName);

        /**
         * @brief Opens the file with the given file name.
         * 
         * @return true if the file is opened successfully, otherwise false.
         */
        boolean openFile();

        /**
         * @brief Closes the currently opened file.
         */
        void closeFile();

        fstream file; /**< The fstream object representing the file. */

    private:
        string fileName; /**< The name of the file to be opened. */
};
