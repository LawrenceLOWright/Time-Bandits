#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header
#include <vector>
#include <sstream>
#include <string>
#include <map>

#include "character.h"
#include "File.h"

using namespace std;
using namespace std::chrono;

class FileRetrival {
	public:
		FileRetrival(File& file);
		string getData(int filePos, int linePos);
		int size();
		vector<string> getData(int filePos);

	private:
		map<int, vector<string>> data;
};