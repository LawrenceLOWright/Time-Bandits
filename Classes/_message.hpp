#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header
#include <vector>


#define UNICODE

using namespace std;
using namespace std::chrono;

// =================================================
// Sets the current background color and text color for any printed text.


// =================================================

class _message {
    public:
        void setMessages (vector<string> msg);

        void addMessage (string msg);

        void printMessages ();

    private:
    vector<string> messages;
};
