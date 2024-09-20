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
	// Comment out the stuff below
	gameEngine engine;
	engine.runGame(load);

	// Show the game engine off here
	//game.changeScreenSize(150, 40);
	//load.allActionLists["showGameEngineOff"][0].setKeycode(13,true);
	//load.allActionLists["showGameEngineOff"][0].setActionDetails("Continue", "1", "Enter", 13);
	//int input = game.loadScene(load.allAssetsLists["mainStreet"], load.allMessageLists["mainStreet"][0], &load.allActionLists["showGameEngineOff"], true);
	//cout << load.allActionLists["showGameEngineOff"][0].getkeyCode();
	//if (load.allActionLists["showGameEngineOff"][0].checkAction(input)) {
	//	game.loadScene(load.allAssetsLists["library"], load.allMessageLists["library"][4], &load.allActionLists["shadyPinesParkActions"], true);
	//}
	return 0;
}

int main()
{
	loadGame load;
	load.load(&startGame);
	return 0;
}