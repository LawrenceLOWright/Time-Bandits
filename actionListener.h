#pragma once
#include <iostream>
#include <windows.h>


using namespace std;
//using namespace std::chrono;

class actionListener {
public:
    char singleInputListen();
    int codeInputListener();
    string stringInputListener();
};

