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


using namespace std;
using namespace std::chrono;


class fileMessagesToString {
public:
    fileMessagesToString(string file);

    vector<message> getLines();


private:
    vector<message> getText(string filePath);

    vector<message> str;

};