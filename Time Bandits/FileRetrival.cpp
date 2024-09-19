#include "FileRetrival.h"

/**
 * @brief Constructs a FileRetrival object and loads data from the provided file.
 * 
 * @param file The file object to retrieve data from.
 */
FileRetrival::FileRetrival(File& file) {
    string tp = "";
    int fileLine = 0;

    // Read each line from the file
    while (getline(file.file, tp)) {
        vector<string> currLine;
        stringstream ss(tp);
        string segment;

        // Split the line by commas and store in a vector   
        while (getline(ss, segment, ',')) {
            currLine.push_back(segment);
        }

        // Store the line's data in the map
        data[fileLine] = currLine;
        fileLine++;
    }
}

/**
 * @brief Retrieves a specific piece of data from a particular file and line position.
 * 
 * @param filePos The index of the file line.
 * @param linePos The index within the line.
 * @return The string value located at the specified position.
 */
string FileRetrival::getData(int filePos, int linePos) {
    return data[filePos][linePos];
}

/**
 * @brief Retrieves an entire line of data from the file.
 * 
 * @param filePos The index of the file line.
 * @return A vector of strings representing the line's data.
 */
vector<string> FileRetrival::getData(int filePos) {
    return data[filePos];
}

/**
 * @brief Retrieves the size of the data map, i.e., the number of lines in the file.
 * 
 * @return The number of lines in the file.
 */
int FileRetrival::size() {
    return data.size();
}
