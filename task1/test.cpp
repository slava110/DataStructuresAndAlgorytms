#include <iostream>
#include "lib.h"
#include "testingutils.h"

int main() {
    cout << "Testing 100 elements..." << endl;
    testSort(insertionSortTest, 100);

    cout << "Testing 1000 elements..." << endl;
    testSort(insertionSortTest, 1000);

    cout << "Testing 10000 elements..." << endl;
    testSort(insertionSortTest, 10000);

    cout << "Testing 100000 elements..." << endl;
    testSort(insertionSortTest, 100000);

    cout << "Testing 1000000 elements..." << endl;
    testSort(insertionSortTest, 1000000);
    return 0;
}