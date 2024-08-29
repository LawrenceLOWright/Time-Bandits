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
void action::setActionDetails(string name, string keyName, int key) {
    actionName = name;
    keyCode = key;
    keyCodeName = keyName;
}

/**
 * @brief Checks if a given key code matches the action's key code.
 * @param code The key code to check against.
 * @return true if the key code matches, false otherwise.
 */
bool action::checkAction(int code) {
    if (code == keyCode) { return true; }
    else { return false; }
}
