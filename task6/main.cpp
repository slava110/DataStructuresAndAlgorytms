#include "lib.h"
#include "ui.h"
#include <fstream>

int main() {
    cout << "Testing KMP text search with UI" << endl;

    string path;
    cout << "Enter text file path:" << endl;
    cout << ">";
    cin >> path;

    string toFind;
    cout << "Enter string to find:" << endl;
    cout << ">";
    cin >> toFind;

    cout << "Searching..." << endl;

    cout << "Path: " << path << endl;
    cout << "ToFind: " << toFind << endl;

    int index;
    unsigned long long C;
    unsigned long long M;

    cout << "File: " << readFile(path) << endl;

    unsigned long long time = measureTime([&](){
        index = searchKMP(readFile(path), toFind, C, M);
    });

    if(index != -1) {
        cout << "Found string at index " << index << endl;
    } else {
        cout << "String not found in provided text!" << endl;
    }

    cout << "Execution time: " << time << endl;
    cout << "Comparisons: " << C << endl;
    cout << "Shifts: " << M << endl;
}