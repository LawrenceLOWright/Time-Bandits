// Time Bandits.cpp : Defines the entry point for the application.
//
#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> 
#include <map>
#include <vector>

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
#include "loadGame.h"
#include "Time Bandits.h"
#include "gameEngine.cpp"

#define UNICODE

using namespace std;


int startGame(loadGame load, gameTools game) {
	gameEngine engine;
	engine.runGame(load);

	return 0;
}

int main()
{
	loadGame load;
	load.load(&startGame);
	return 0;
}