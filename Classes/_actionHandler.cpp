#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> 
#include <vector>
#include "_actionListener.hpp"

#define UNICODE

using namespace std;
using namespace std::chrono;

class _actionHandler(){
    public:
        int getSingleInput(){

        }

    private:
        _actionListener listener;
}