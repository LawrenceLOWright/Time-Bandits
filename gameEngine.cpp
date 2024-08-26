#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> 
#include <map>

#include "Classes\_char.hpp"
#include "Classes\_color.cpp"
#include "Classes\_sprite.hpp"
#include "Classes\fileToString.cpp"
#include "Classes\fileMessagesToString.cpp"
#include "Classes\_message.hpp"
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
        Sleep(100);
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

    int loadScene (vector<_char> scene, _message text, vector<_action> actions) {
        int keyCode = 0;
        _actionListener action;

        loadScreen(scene);
        text.printMessages();

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

    int loadScene (vector<_char> scene, _message text, vector<_action> actions, bool actionHeader) {
        int keyCode = 0;
        _actionListener action;
        // [D : Description] [enter : Continue]
        string header = " <     Available Actions : ";

        for (int e = 0; e < actions.size(); e++) {
            header = header + " [" + actions[e].getKeyCodeName() + " : " + actions[e].getActionName() + "]";
        }

        loadScreen(scene);
        cout << header + "\n---------------" << endl;
        text.printMessages();

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


        // Set the encoding to utf-8 for cmd
        system("chcp 65001");

        // Set screen size to 120 x by 40 y
        screen.changeScreenSize(150,40);

        // ========================================





        // ===========   Load actions     =========
        enter.setActionDetails("Continue","enter", 13);
        description.setActionDetails("Description", "D", 68);
        pickDandelions.setActionDetails("Pick Dandelions", "1" , 49);
        swings.setActionDetails("Sit on Swings", "2", 50);



        vector<_action> basic{enter};
        vector<_action> basicArea{enter,description};
        vector<_action> tutorial1{description};
        vector<_action> shadyPinesParkActions{enter, description, pickDandelions, swings};


        allActionLists["basic"] = basic;
        allActionLists["basicArea"] = basicArea;
        allActionLists["tutorial1"] = tutorial1;
        allActionLists["shadyPinesParkActions"] = shadyPinesParkActions;
        

        // ========================================




        // ===========   Load assets     =========
        mainMenu = screen.loadAsset("Backgrounds/mainMenu/mainMenu");
        shadyPinesPark = screen.loadAsset("Backgrounds/shadyPinesPark/shadyPinesPark");
        // ========================================


        fileMessagesToString shadydata = fileMessagesToString("shadyPines");
        vector<_message> shadyPinesText = shadydata.getLines();
        allMessageLists["shadyPinesPark"] = shadyPinesText;



        // ===============================================================
        // ===============================================================
        // ===============================================================

        // Main Menu
        loadMainMenu();
        
        
        
        // ===============================================================
        // ===============================================================
        // ===============================================================


        // ========  Clean up code at end     =====

        c.setDefault();

        // ========================================
    }

    // Loads Shady Pines Park and all of its options with what each thing does
    void loadShadyPinesPark(){

        int input = screen.loadScene(shadyPinesPark, allMessageLists["shadyPinesPark"][0], allActionLists["shadyPinesParkActions"], true);

        if (input == pickDandelions.getkeyCode()){screen.loadScene(shadyPinesPark, allMessageLists["shadyPinesPark"][4], allActionLists["basic"], true);}
        if (input == swings.getkeyCode()) {screen.loadScene(shadyPinesPark, allMessageLists["shadyPinesPark"][5], allActionLists["basic"], true);}
        

        loadMainMenu();
        
    }

    // Loads the Main menu.
    void loadMainMenu(){
        screen.loadScene(mainMenu,"",allActionLists["basic"]);

        screen.changeScreenSize(150,50);
        screen.loadScene(mainMenu, allMessageLists["shadyPinesPark"][0],  allActionLists["basic"]);
        screen.loadScene(mainMenu, allMessageLists["shadyPinesPark"][1], allActionLists["tutorial1"]);

        screen.loadScene(shadyPinesPark, allMessageLists["shadyPinesPark"][2], allActionLists["basic"],true);
        loadShadyPinesPark();
    }

    private:
        _action enter, description, pickDandelions, swings;
        Screen screen;
        Timer t;
        _color c;
        vector<_char> mainMenu;
        vector<_char> shadyPinesPark;
        map<string, vector<_action>> allActionLists;
        map<string, vector<_message>> allMessageLists;
};

// ===============================================================
// MAIN CODE
// ===============================================================

int main() {
    
    Game game;
    

    game.LoadGame();
    

    

    // system("@echo off");
}

