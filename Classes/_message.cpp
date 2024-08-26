#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header
#include <vector>
#include "_message.hpp"

#define UNICODE

using namespace std;
using namespace std::chrono;

// =================================================
// Sets the current background color and text color for any printed text.


// =================================================


        void _message::setMessages (vector<string> msg) {messages = msg;}

        void _message::addMessage (string msg) {messages.push_back(msg);}

        void _message::printMessages () {
            for (int x = 0; x < messages.size(); x++) {
                cout << messages[x] << endl;
            }
        }
