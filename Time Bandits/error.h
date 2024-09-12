#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header
#include <vector>
#include <map>
#include "character.h"
#include "action.h"

using namespace std;
using namespace std::chrono;

class error {
	public:
		error(string message);

	private:
};