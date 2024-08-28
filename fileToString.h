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


class fileToString {
public:
    fileToString(string file);

    string getText(string filePath);

    string getText();

    // vector<_char>

    vector<character> textToChar();



private:
    string str;
    string txtColor;
    string backgroundColor;

};

