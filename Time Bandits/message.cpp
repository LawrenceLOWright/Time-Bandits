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

/**
 * @brief Sets the vector of messages for the object.
 * 
 * @param msg A vector of strings representing the messages to be stored.
 */
void message::setMessages(const vector<string> msg) { messages = msg; }

/**
 * @brief Adds a single message to the existing list of messages.
 * 
 * @param msg A string representing the message to be added.
 */
void message::addMessage(string msg) { messages.push_back(msg); }

/**
 * @brief Prints all stored messages to the standard output.
 * 
 * Each message is printed on a new line.
 */
void message::printMessages() {
    for (int x = 0; x < messages.size(); x++) {cout << messages[x] << endl;}
}

string message::getMessage() {
    string msg = "";
    for (int x = 0; x < messages.size(); x++) {msg = msg + messages[x];}

    return msg;
}
