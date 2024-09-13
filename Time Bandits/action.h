#pragma once
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
class action {
public:
    /**
     * @brief Retrieves the name of the action.
     * @return A string representing the name of the action.
     */
    string getActionName();

    /**
     * @brief Retrieves the name of the key code associated with the action.
     * @return A string representing the name of the key code.
     */
    string getKeyCodeName();

    /**
     * @brief Retrieves the integer value of the key code.
     * @return An integer representing the key code.
     */
    int getkeyCode();

    /**
     * @brief Sets the details of the action, including the action name, key code name, and key code.
     * @param name The name of the action.
     * @param keyName The name of the key code.
     * @param key The integer value of the key code.
     */
    void setActionDetails(string name, string keyName, int key);

    /**
     * @brief Checks if a given key code matches the action's key code.
     * @param code The key code to check against.
     * @return true if the key code matches, false otherwise.
     */
    bool checkAction(int code);

    /**
     * @brief retrives if the action is active or inactive (if is on or has been turned off).
     * @returns true if the action is active (on) or false if action is inactive (off)
     */
    bool isActive();

    /**
     * @brief if the action is active, it is turned inactive, if the action is inactive, it is turn active
     */
    void setActive(bool setTo);
       

private:
    string actionName = "None";  /**< The name of the action. */
    string keyCodeName = "";     /**< The name of the key code associated with the action. */
    int keyCode = 0;             /**< The integer value of the key code. */
    bool activity = true;           /**< Default is true, used to turn off or on an event*/
};
