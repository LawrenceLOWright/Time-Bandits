#include "File.h"

File::File(string fileName) {File::fileName = fileName;}

boolean File::openFile() {
    file.open(fileName, ios::in);
    if (!file.is_open()) {
        error e = error("File Missing");
        throw runtime_error("File is missing");
    }

    return true;
}

void File::closeFile() {file.close();}
