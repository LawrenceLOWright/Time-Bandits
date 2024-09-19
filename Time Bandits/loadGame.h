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
#include <functional>

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
#include "fileTextToString.h"
#include "fileAssetsToString.h"
#include "File.h"


using namespace std;
using namespace std::chrono;

class loadGame {
public:
	loadGame();
	void load(int (*startGame) (loadGame load, gameTools game));
	vector<action> actions;
	map<string, vector<action>> allActionLists;
	map<string, vector<message>> allMessageLists;
	map < string, vector<character>> allAssetsLists;

	//int loadScene(string sceneName, int location);


private:
	string retrieveSetting(string settingName);
};
