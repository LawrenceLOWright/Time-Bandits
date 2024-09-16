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

#include "error.h"
#include "character.h"
#include "color.h"
#include "fileToString.h"
#include "fileMessagesToString.h"
#include "fileActionsToString.h"
#include "message.h"
#include "timer.h"
#include "action.h"
#include "actionListener.h"
#include "gameTools.h"



using namespace std;
using namespace std::chrono;

class loadGame {
	public:
		loadGame();
		vector<action> actions;
		map<string, vector<action>> allActionLists;



	private:
		string retrieveSetting(string settingName);
};