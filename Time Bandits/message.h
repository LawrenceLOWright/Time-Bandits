#pragma once

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
 * @class message
 * @brief A class to handle and manipulate a collection of messages.
 * 
 * The message class provides functionalities to set, add, and print
 * a collection of string messages. It acts as a simple container and
 * manager for a list of messages.
 */
class message {
    public:
        /**
         * @brief Sets the vector of messages for the object.
         * 
         * @param msg A vector of strings representing the messages to be stored.
         */
        void setMessages(vector<string> msg);

        /**
         * @brief Adds a single message to the existing list of messages.
         * 
         * @param msg A string representing the message to be added.
         */
        void addMessage(string msg);

        /**
         * @brief Prints all stored messages to the standard output.
         * 
         * Each message is printed on a new line.
         */
        void printMessages();

    private:
        vector<string> messages; /**< Vector to store messages */
};
