#pragma once
#include <iostream>
#include <windows.h>


#define UNICODE

using namespace std;
using namespace std::chrono;

class _actionListener{
    public:
        char singleInputListen();
        int codeInputListener();
        string stringInputListener();
};
