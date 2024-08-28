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

class action {

public:
    string getActionName();
    string getKeyCodeName();
    int getkeyCode();

    void setActionDetails(string name, string keyName, int key);

    bool checkAction(int code);


private:
    string actionName = "None";
    string keyCodeName = "";
    int keyCode = 0;
};