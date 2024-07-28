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

// =================================================
// Deals with individual characters.


// =================================================

class _char {
    public:
    string character;
    int txtColor = 1;
    int backgroundColor = 1;

    _char (string cha, int col, int back) {
        character = cha;
        txtColor = col;
        backgroundColor = back;
    }
};