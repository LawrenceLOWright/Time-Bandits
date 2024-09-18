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
#include "error.h"
#include <sstream>

using namespace std;
using namespace std::chrono;

class File {
	public:
		File(string fileName);
		boolean openFile();
		void closeFile();
		fstream file;

	private:
		string fileName;
		
};