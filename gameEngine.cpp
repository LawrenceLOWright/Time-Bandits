#include <iostream>
#include <string>
using namespace std;

class Screen {
    public:

    // Refresh the screen to a new frame.
    void refreshScreen () {
        std::string command = "mode con: cols=" + std::to_string(screenWidth) + " lines=" + std::to_string(screenHeight);
        system(command.c_str());
    }

    private:
    int screenWidth = 120;
    int screenHeight = 40;
};

int main() {
    cout << "Welcome to Command Prompt!\n";
    Screen screen;
    screen.refreshScreen();
    system("Pause");
}