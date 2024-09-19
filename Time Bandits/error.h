#pragma once

#include <iostream>
#include <string>

using namespace std;

class error {
    public:
        /**
         * @brief Constructs an error object with a message.
         * 
         * @param message The error message.
         */
        error(string message);

    private:
        string errorMessage; /**< Stores the error message. */
};
