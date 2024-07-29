#include <iostream>
#include <string>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <chrono> // Include the chrono header


#define UNICODE

using namespace std;
using namespace std::chrono;


// =================================================
// Used for timing frames and functions.


// =================================================

class Timer {
    public:
        Timer() : start(high_resolution_clock::now()), stop(high_resolution_clock::now()) {}

        void startTimer() {start = high_resolution_clock::now();}

        void stopTimer() {stop = high_resolution_clock::now();}

        void returnDuration() {
            auto duration = duration_cast<milliseconds>(stop - start);
            cout << "Time taken: " << duration.count() << " milliseconds" << endl;
        }

    private:
        time_point<high_resolution_clock> start;
        time_point<high_resolution_clock> stop;
};