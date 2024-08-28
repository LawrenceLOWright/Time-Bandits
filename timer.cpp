#include "timer.h"

#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header

using namespace std;
using namespace std::chrono;


// =================================================
// Used for timing frames and functions.


// =================================================


        timer::timer() : start(high_resolution_clock::now()), stop(high_resolution_clock::now()) {}

        void timer::startTimer() {start = high_resolution_clock::now();}

        void timer::stopTimer() {stop = high_resolution_clock::now();}

        void timer::returnDuration() {
            auto duration = duration_cast<milliseconds>(stop - start);
            cout << "Time taken: " << duration.count() << " milliseconds" << endl;
        }


