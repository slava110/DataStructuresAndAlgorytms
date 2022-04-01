#ifndef DSAA_CONSOLEUTILS_H
#define DSAA_CONSOLEUTILS_H
#include <iostream>
#include <limits>

using namespace std;

void clearScreen() {
    system("cls");
}

void pause() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

#endif //DSAA_CONSOLEUTILS_H
