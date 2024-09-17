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
     * @param Overload keyName The name of the key code.
     * @param Overloadkey The integer value of the key code.
     */
    void setActionDetails(string name, string activity);
    void setActionDetails(string name, string activity, string keyName, int key);

    /**
     * @brief sets the actions keycode to a key.
     * @param key to change keycode to.
     */
    void setKeycode(int key);

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
     * @brief sets the action to the input activity, this one is for boolean input
     * @param sets the action to the given boolean
     */
    void setActive(bool setTo);

    /**
     * @brief sets the action to the input activity, this one is for string input
     * @param sets the action to the given string if the string is "1" (true) or "0" (false)
     */
    void setActive(string setTo);
       

private:
    string actionName = "None";  /**< The name of the action. */
    string keyCodeName = "";     /**< The name of the key code associated with the action. */
    int keyCode = 0;             /**< The integer value of the key code. */
    bool activity = true;           /**< Default is true, used to turn off or on an event*/
};
