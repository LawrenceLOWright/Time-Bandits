#include "action.h"
#include "error.h"

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 * @class action
 * @brief A class representing an action associated with a specific key code.
 */

/**
 * @brief Retrieves the name of the action.
 * @return A string representing the name of the action.
 */
string action::getActionName() { return actionName; }

/**
 * @brief Retrieves the name of the key code associated with the action.
 * @return A string representing the name of the key code.
 */
string action::getKeyCodeName() { return keyCodeName; }

/**
 * @brief Retrieves the integer value of the key code.
 * @return An integer representing the key code.
 */
int action::getkeyCode() { return keyCode; }

/**
 * @brief Sets the details of the action, including the action name, key code name, and key code.
 * @param name The name of the action.
 * @param keyName The name of the key code.
 * @param key The integer value of the key code.
 */
void action::setActionDetails(string name, string activity, string keyName, int key) {
    cout << "extended action detail set" << endl;
    actionName = name;
    keyCode = key;
    keyCodeName = keyName;
    setActive(activity);
}

void action::setActionDetails(string name, string activity) {
    cout << "short action detail set" << endl;
    actionName = name;
    setActive(activity);
}

void action::setKeycode(int key) {
    cout << "attempting to change keyCode" << endl;
    switch (keyCode)
    {
        case(13):
            cout << "Special case Found, skipping" << endl;
            return;
        case(68):
            cout << "Special case Found, skipping" << endl;
            return;
        default:
            keyCode = key + 48;
            keyCodeName = to_string(key);
    }
    cout << actionName << "'s keycode is " << keyCode << endl;
}

/**
 * @brief Checks if a given key code matches the action's key code.
 * @param code The key code to check against.
 * @return true if the key code matches, false otherwise.
 */
bool action::checkAction(int code) {
    cout << "checking " << actionName << " input: " << code << ">" << keyCode << "; ";
    if (code == keyCode) { return true; }
    else { return false; }
}

/**
 * @brief retrives if the action is active or inactive (if is on or has been turned off).
 * @returns true if the action is active (on) or false if action is inactive (off)
 */
bool action::isActive(){ return activity; }

/**
 * @brief if the action is active, it is turned inactive, if the action is inactive, it is turn active
 */
void action::setActive(bool setTo) {
    activity = setTo;
}

void action::setActive(string setTo) {
    if (setTo == "1") {
        activity = true;
        cout << actionName << " is active " << endl;
        return;
    }
    if (setTo == "0") {
        activity = false;
        cout << actionName << " is inactive " << endl;
        return;
    }
    error e = error("Invalid String Input for Action Activity");

}
