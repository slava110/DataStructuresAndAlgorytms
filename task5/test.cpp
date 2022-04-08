#include <iostream>
#include "lib.h"
#include "testingutils.h"

void incrementingArray(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

void decrementingArray(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = size - 1 - i;
    }
}

int main() {
    cout << "=== Testing on incrementing array ===" << endl;

    cout << "Testing 100 elements..." << endl;
    testSearch(binarySearch, 100, incrementingArray);

    cout << "Testing 1000 elements..." << endl;
    testSearch(binarySearch, 1000, incrementingArray);

    cout << "Testing 10000 elements..." << endl;
    testSearch(binarySearch, 10000, incrementingArray);

    cout << "Testing 100000 elements..." << endl;
    testSearch(binarySearch, 100000, incrementingArray);

    cout << "Testing 1000000 elements..." << endl;
    testSearch(binarySearch, 1000000, incrementingArray);

    cout << "=== Testing on decrementing array ===" << endl;

    cout << "Testing 100 elements..." << endl;
    testSearch(binarySearch, 100, decrementingArray);

    cout << "Testing 1000 elements..." << endl;
    testSearch(binarySearch, 1000, decrementingArray);

    cout << "Testing 10000 elements..." << endl;
    testSearch(binarySearch, 10000, decrementingArray);

    cout << "Testing 100000 elements..." << endl;
    testSearch(binarySearch, 100000, decrementingArray);

    cout << "Testing 1000000 elements..." << endl;
    testSearch(binarySearch, 1000000, decrementingArray);

    cout << "=== Testing on random array ===" << endl;

    cout << "Testing 100 elements..." << endl;
    testSearch(binarySearch, 100);

    cout << "Testing 1000 elements..." << endl;
    testSearch(binarySearch, 1000);

    cout << "Testing 10000 elements..." << endl;
    testSearch(binarySearch, 10000);

    cout << "Testing 100000 elements..." << endl;
    testSearch(binarySearch, 100000);

    cout << "Testing 1000000 elements..." << endl;
    testSearch(binarySearch, 1000000);

}