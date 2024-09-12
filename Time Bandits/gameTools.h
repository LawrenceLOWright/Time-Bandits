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
#include "color.h"
#include "fileToString.h"
#include "fileMessagesToString.h"
#include "fileActionsToString.h"
#include "message.h"
#include "timer.h"
#include "action.h"
#include "actionListener.h"



using namespace std;
using namespace std::chrono;

class gameTools {
	public:
		void refreshScreen();
		void changeScreenSize(int width, int height);
		vector<character> loadAsset(string fileName);
		void loadScreen(vector<character> vec);
		int loadScene(vector<character> scene, string text, vector<action> actions);
		int loadScene(vector<character> scene, string text, vector<action> actions, bool actionHeader);
		int loadScene(vector<character> scene, message text, vector<action> actions, bool actionHeader);
		int loadScene(vector<character> scene, message text, vector<action> actions);

	private:
		int screenWidth = 120; /**< The width of the screen in characters. */
		int screenHeight = 200; /**< The height of the screen in characters. */
};