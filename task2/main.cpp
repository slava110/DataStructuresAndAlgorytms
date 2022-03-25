#include <iostream>
#include "arrayio.h"
#include "lib.h"

using namespace std;

int main() {
    int size = 5;
    int* arr = new int[size];

    arrInput(arr, size);
    selectionSort(arr, size);
    arrOutput(arr, size);

    delete[] arr;
    return 0;
}