#include "message.h"

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header
#include <vector>


using namespace std;
using namespace std::chrono;

// =================================================
// Sets the current background color and text color for any printed text.


// =================================================


void message::setMessages(vector<string> msg) { messages = msg; }

void message::addMessage(string msg) { messages.push_back(msg); }

void message::printMessages() {
    for (int x = 0; x < messages.size(); x++) {
        cout << messages[x] << endl;
    }
}

string message::getMessage(int location) {
    string msg = "";
    for (int x = 0; x < messages.size(); x++) {
        msg = msg + messages[x];
    }

    return msg;
}
