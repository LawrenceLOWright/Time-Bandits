#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono>


#define UNICODE

using namespace std;
using namespace std::chrono;

class _action {

    public:
        string getActionName () {return actionName;}
        string getKeyCodeName () {return keyCodeName;}
        int getkeyCode () {return keyCode;}

        void setActionDetails (string name, string keyName,int key) {
            actionName = name;
            keyCode = key;
            keyCodeName = keyName;
        }

        bool checkAction (int code) {
            if (code == keyCode) {return true;} 
            else {return false;}
        }


    private:
        string actionName = "None";
        string keyCodeName = "";
        int keyCode = 0;
};