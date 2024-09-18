#include "error.h"


error::error(string message) {
	std::string tp = message;
	std::string command = "msg %username% " + tp;

	system(command.c_str());
}