#include "error.h"

/**
 * @brief Constructs an error object and sends a Windows message with the error message.
 * 
 * This constructor sends a message to the current user using the Windows `msg` command.
 * 
 * @param message The error message to send.
 */

error::error(string message) {
	std::string tp = message;
	std::string command = "msg %username% " + tp;

	system(command.c_str());
}