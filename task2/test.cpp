#include <iostream>
#include "arrayio.h"
#include "lib.h"

int main() {
    int size = 5;
    int* arr = new int[size];

    arrRandomize(arr, size);
    insertionSort(arr, size);
    arrOutput(arr, size);

    delete[] arr;
    return 0;
}