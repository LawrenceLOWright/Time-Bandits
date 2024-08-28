#include "fileMessagesToString.h"

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header
#include <vector>
#include "character.h"
#include "message.h"


using namespace std;
using namespace std::chrono;



    fileMessagesToString::fileMessagesToString(string file) {
        string filePath = file + ".text";

        str = getText(filePath);
    }

    vector<message> fileMessagesToString::getLines() { return str; }



    vector<message> fileMessagesToString::getText(string filePath) {
        fstream file;
        file.open(filePath, ios::in);
        if (!file.is_open()) { return std::vector<message>(); }

        vector<message> lines;
        string tp = "";
        int pos = 0;
        while (getline(file, tp)) {
            vector<string> msg;
            while (tp.length() > 85) {
                for (int splitChar = tp.length(); splitChar > 0; splitChar--) {
                    if (splitChar > 85) { splitChar = 85; }
                    if (tp.at(splitChar) == ' ') {
                        string cutStr = tp.substr(0, splitChar);
                        tp = tp.substr(splitChar + 1);
                        msg.push_back(" <     " + cutStr);
                        break;
                    }
                }
            }
            msg.push_back(" <     " + tp);
            message mess;
            mess.setMessages(msg);
            lines.push_back(mess);

        }

        file.close();
        return lines;
    }

