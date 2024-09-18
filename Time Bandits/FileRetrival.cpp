#include "FileRetrival.h"


FileRetrival::FileRetrival(File& file) {
    string tp = "";
    int fileLine = 0;

    while (getline(file.file, tp)) {
        vector<string> currLine;
        stringstream ss(tp);
        string segment;

        //Split by comma
        while (getline(ss, segment, ',')) {currLine.push_back(segment);}

        data[fileLine] = currLine;
        fileLine++;
    }

}

string FileRetrival::getData(int filePos, int linePos) {return data[filePos][linePos];}

int FileRetrival::size() {return data.size();}