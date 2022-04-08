#include <iostream>
#include "lib.h"
#include "testingutils.h"

void testOn(string filePath, string toFind) {
    cout << "Searching..." << endl;

    int index;
    unsigned long long C;
    unsigned long long M;

    unsigned long long time = measureTime([&](){
        index = searchKMP(readFile(filePath), toFind, C, M);
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

int main() {
    testOn(R"(../book1.txt)", "синяя шинель");
    cout << "=======" << endl;
    testOn(R"(../book2.txt)", "Теща");
    cout << "=======" << endl;
    testOn(R"(../book3.txt)", "вектор структур Operation");
}