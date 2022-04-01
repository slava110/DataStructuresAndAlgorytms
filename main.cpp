#include <iostream>
#include <map>
#include <functional>
#include "consoleutils.h"

using namespace std;

static map<string, function<void ()>> tasks;

void registerTasks() {
    //TODO Register tasks here
    // For that I'll need to think about whole project structure
    // Because UI functions should be included here. And not `main.cpp`
}

int main() {
    cout << "Data Structures and Algorithms v1.0" << endl;

    string input;
    while (true) {
        cout << "Type task id or `exit` to exit program:" << endl;
        cout << ">";
        cin >> input;
        if(input == "exit")
            break;

        auto task = tasks.find(input);
        if(task != tasks.end()) {
            clearScreen();
            task -> second();
            cout << endl;
            cout << "Task execution finished. Press any key to continue" << endl;
            pause();
            clearScreen();
        } else {
            cout << "Task with id `" << input << "` not found!" << endl;
            pause();
            clearScreen();
        }
    }
}