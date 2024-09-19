#include "File.h"

/**
 * @brief Constructs a File object with the given file name.
 * 
 * @param fileName The name of the file to be opened.
 */
File::File(string fileName) : fileName(fileName) {}

/**
 * @brief Opens the file with the given file name.
 * 
 * @return true if the file is opened successfully, otherwise false.
 * 
 * @throws runtime_error If the file cannot be opened.
 */
boolean File::openFile() {
    file.open(fileName, ios::in);
    if (!file.is_open()) {
        error e = error("File Missing");
        throw runtime_error("File is missing");
    }

    return true;
}

/**
 * @brief Closes the currently opened file.
 */
void File::closeFile() {
    file.close();
}
