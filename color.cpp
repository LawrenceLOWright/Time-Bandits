#include "color.h"


// =================================================
// Sets the current background color and text color for any printed text.


// =================================================


    void color::setCurrentColor(int txt, int bg) {
        textColor = txt;
        bgColor = bg;

        SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
    }

    void color::setDefault() { SetConsoleTextAttribute(hConsole, 7); }

