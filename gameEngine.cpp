#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> 

#include "Classes\_char.hpp"
#include "Classes\_color.cpp"
#include "Classes\_sprite.hpp"
#include "Classes\fileToString.cpp"
#include "Classes\Timer.cpp"
#include "Classes\_scene.hpp"
#include "Classes\_action.cpp"
#include "Classes\_actionListener.cpp"

#define UNICODE

using namespace std;
using namespace std::chrono; // To avoid typing std::chrono:: every time





// =================================================
// Deals with code relating to the screen


// =================================================

class Screen {
public:
    // Refresh the screen to a new frame.
    void refreshScreen() {
        // 12.33 milliseconds
        //std::string command = "mode con: cols=" + std::to_string(screenWidth) + " lines=" + std::to_string(screenHeight);
        //system(command.c_str());
        system("cls");
        // Print text here
        //cout << txt1;
        //cout.flush();
        //std::this_thread::sleep_for(chrono::milliseconds(10));
    }

    void changeScreenSize (int width, int height) {
        screenWidth = width;
        screenHeight = height;

        std::string command = "mode con: cols=" + std::to_string(screenWidth) + " lines=" + std::to_string(screenHeight);
        system(command.c_str());

    }

    vector<_char> loadAsset (string fileName) {
        fileToString f = fileToString(fileName);
        std::vector<_char> vec = f.textToChar();
        return vec;
    }

    void loadScreen (vector<_char> vec) {
        refreshScreen();
        
        _color color;

        // Must be kept in main code
        int prevCol2 = 999;
        int prevCol = 999;

        for (int x = 0; x < vec.size(); x++) {
            int col2 = vec[x].getBackgroundColor();
            int col = vec[x].getTextColor();
            if (col == prevCol && col2 == prevCol2) {prevCol = col;}
            else {
                prevCol = col;
                prevCol2 = col2;
                color.setCurrentColor(col,col2);
            }
            
            cout << vec[x].getChar();
        }

        color.setDefault();
    }

    int loadScene (vector<_char> scene, string text, vector<_action> actions) {
        int keyCode = 0;
        _actionListener action;

        loadScreen(scene);
        cout << text << endl;

        while (true) {
            keyCode = action.codeInputListener();
            
            // If certain button is pressed
            for (int x = 0; x < actions.size(); x++) {
                if (actions[x].checkAction(keyCode) == true) {return keyCode;}
            }

        }

    }

    int loadScene (vector<_char> scene, string text, vector<_action> actions, bool actionHeader) {
        int keyCode = 0;
        _actionListener action;
        // [D : Description] [enter : Continue]
        string header = " <     Available Actions : ";

        for (int e = 0; e < actions.size(); e++) {
            header = header + " [" + actions[e].getKeyCodeName() + " : " + actions[e].getActionName() + "]";
        }

        loadScreen(scene);
        cout << header + "\n---------------" << endl;
        cout << text << endl;

        while (true) {
            keyCode = action.codeInputListener();

            // If certain button is pressed
            for (int x = 0; x < actions.size(); x++) {
                if (actions[x].checkAction(keyCode) == true) {return keyCode;}
            }

        }

    }

private:
    int screenWidth = 120;
    int screenHeight = 200;
};


// =================================================
// Deals with the game script


// =================================================
class Game {
    public:
    void LoadGame () {


        // ===========   Load Game details    =========
        Screen screen;
        Timer t;
        _color c;

        // Set the encoding to utf-8 for cmd
        system("chcp 65001");

        // Set screen size to 120 x by 40 y
        screen.changeScreenSize(150,40);

        // ========================================





        // ===========   Load actions     =========
        _action enter, description;
        enter.setActionDetails("Continue","enter",13);
        description.setActionDetails("Description", "D",68);

        vector<_action> basic{enter};
        vector<_action> basicArea{enter,description};
        vector<_action> tutorial1{description};

        // ========================================




        // ===========   Load assets     =========
        vector<_char> mainMenu = screen.loadAsset("Backgrounds/mainMenu/mainMenu");
        vector<_char> shadyPinesPark = screen.loadAsset("Backgrounds/shadyPinesPark/shadyPinesPark");
        // ========================================
        

        // ===============================================================
        // ===============================================================
        // ===============================================================

        // Main Menu
        screen.loadScene(mainMenu,"",basic);

        // Shady Pines Park
        screen.changeScreenSize(150,50);
        screen.loadScene(mainMenu, " <     Where am I? [Press 'enter' to continue]",  basic);
        screen.loadScene(mainMenu, " <     [You can press 'D' for a description of the area]", tutorial1);
        screen.loadScene(shadyPinesPark, " <     You realise that you are currently in Shady Pines Park. \n <     You see a neglected playground, covered in graffiti and grime, standing starkly against the cloudy sky. \n <     A sea of dandelions have overrun the grassy field around it, \n <     their bright yellow heads a stark contrast to the park's otherwise desolate state.", basic,true);
        
        // ===============================================================
        // ===============================================================
        // ===============================================================


        // ========  Clean up code at end     =====

        c.setDefault();

        // ========================================
    }
};

// ===============================================================
// MAIN CODE
// ===============================================================

int main() {
    
    Game game;
    

    game.LoadGame();
    

    

    // system("@echo off");
}

