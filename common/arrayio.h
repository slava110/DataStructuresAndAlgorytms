#ifndef DSAA_ARRAYIO_H
#define DSAA_ARRAYIO_H
#include <iostream>

using namespace std;

void arrInput(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

void arrRandomize(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand(); // NOLINT(cert-msc50-cpp)
    }
}

void arrOutput(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << endl;
    }
}
#endif