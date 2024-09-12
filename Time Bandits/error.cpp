


#include "error.h"

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header
#include <vector>
#include <sstream>
#include "character.h"

using namespace std;
using namespace std::chrono;

error::error(string message) {
	std::string tp = message;
	std::string command = "msg %username% " + tp;

	system(command.c_str());
}