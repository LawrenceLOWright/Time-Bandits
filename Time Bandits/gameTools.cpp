
#include "gameTools.h"

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header
#include <vector>
#include <map>


using namespace std;
using namespace std::chrono;

/**
* @brief Refreshes the screen to a new frame.
* Clears the console screen using the system "cls" command.
*/
void gameTools::refreshScreen() {system("cls");}

/**
* @brief Changes the size of the console screen.
*
* @param width  New width of the console.
* @param height New height of the console.
*/
void gameTools::changeScreenSize(int width, int height) {
    screenWidth = width;
    screenHeight = height;

    std::string command = "mode con: cols=" + std::to_string(screenWidth) + " lines=" + std::to_string(screenHeight);
    system(command.c_str());
}

/**
* @brief Loads character data from a file and returns a vector of characters.
*
* @param fileName Name of the file to load.
* @return A vector of character objects representing the file content.
*/
vector<character> gameTools::loadAsset(string fileName) {
    fileToString f = fileToString(fileName);
    std::vector<character> vec = f.textToChar();
    return vec;
}

/**
* @brief Loads and displays a scene using the vector of character objects.
*
* @param vec Vector of character objects to display.
*/
void gameTools::loadScreen(vector<character> vec) {
    gameTools game;
    game.refreshScreen();

    color color;
    int prevCol2 = 999;
    int prevCol = 999;

    for (int x = 0; x < vec.size(); x++) {
        int col2 = vec[x].getBackgroundColor();
        int col = vec[x].getTextColor();
        if (col == prevCol && col2 == prevCol2) { prevCol = col; }
        else {
            prevCol = col;
            prevCol2 = col2;
            color.setCurrentColor(col, col2);
        }

        cout << vec[x].getChar();
    }

    color.setDefault();
    Sleep(100);
}

/**
     * @brief Loads a scene, displays text, and waits for user input to trigger actions.
     *
     * @param scene   Vector of character objects representing the scene.
     * @param text    Additional text to display on the scene.
     * @param actions Vector of action objects representing possible user actions.
     * @return The key code of the action performed.
     */
int gameTools::loadScene(vector<character> scene, string text, vector<action> actions) {
    
    loadScreen(scene);
    cout << text << endl;

    return checkInputs(actions);
}

/**
     * @brief Loads a scene with an action header, displays text, and waits for user input.
     *
     * @param scene        Vector of character objects representing the scene.
     * @param text         Additional text to display on the scene.
     * @param actions      Vector of action objects representing possible user actions.
     * @param actionHeader Boolean flag to indicate whether to show the action header.
     * @return The key code of the action performed.
     */
int gameTools::loadScene(vector<character> scene, string text, vector<action> actions, bool actionHeader) {
    string header = writeActions(actions);

    loadScreen(scene);
    cout << header + "\n---------------" << endl;
    cout << text << endl;

    return checkInputs(actions);
}

int gameTools::loadScene(vector<character> scene, message text, vector<action> actions, bool actionHeader) {
    

    string header = writeActions(actions);

    gameTools game;
    game.loadScreen(scene);
    cout << header + "\n---------------" << endl;
    text.printMessages();

    return checkInputs(actions);

    
}

int gameTools::loadScene(vector<character> scene, message text, vector<action> actions) {
    

    gameTools game;
    game.loadScreen(scene);
    text.printMessages();

    return checkInputs(actions);

    
}

int gameTools::checkInputs(vector<action> actions) {
    int keyCode = 0;
    actionListener action;
    while (true) {
        keyCode = action.codeInputListener();

        // Check if certain button is pressed
        for (int x = 0; x < actions.size(); x++) {
            if (actions[x].isActive())
            {
                if (actions[x].checkAction(keyCode) == true) { return keyCode; }
            }
        }
    }
}

string gameTools::writeActions(vector<action> actions) {
    string header = " <     Available Actions : ";
    for (int e = 0; e < actions.size(); e++) {
        if (actions[e].isActive()) {
            header = header + " [" + actions[e].getKeyCodeName() + " : " + actions[e].getActionName() + "]";
        }

    }
    return header;
}