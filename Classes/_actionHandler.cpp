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
        int getMultiChoice(int range){
            int input = listener.singleInputListen() - '0';
            if (input => 0 && input <= range){
                return input;
            }
        }

        vector<string> getlongAnswer(vector<string> keyWords){
            vector<string> foundWords;
            string input = listener.stringInputListener();
            for(auto &i : keyWords){
                if (input.find(i)){
                    foundWords.pushBack(i);
                }
            }
        }

    private:
        _actionListener listener;
}