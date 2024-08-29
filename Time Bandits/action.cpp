#include "action.h"

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono>


using namespace std;
using namespace std::chrono;

    string action::getActionName() { return actionName; }
    string action::getKeyCodeName() { return keyCodeName; }
    int action::getkeyCode() { return keyCode; }

    void action::setActionDetails(string name, string keyName, int key) {
        actionName = name;
        keyCode = key;
        keyCodeName = keyName;
    }

    bool action::checkAction(int code) {
        if (code == keyCode) { return true; }
        else { return false; }
    }

