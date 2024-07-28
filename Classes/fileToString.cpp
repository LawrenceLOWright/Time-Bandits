#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header


#define UNICODE

using namespace std;
using namespace std::chrono;

class fileToString {
    public:
        string content; 

        txtToString(const string& filePath) {
            fstream file;
            file.open(filePath,ios::in);
            if (!file.is_open()) {return 0;}

            string tp = "";
            while(getline(file, tp)){ //read data from file object and put it into string.
                cout << tp << "\n"; //print the data of the string
            }
            file.close();
        }


        string getContent() const {
            return content;
        }
};

