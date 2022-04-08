#ifndef DSAA_LIB_H
#define DSAA_LIB_H

#include <iostream>

int binarySearch1(int array[], int x, int low, int high) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If found at mid, then return it
        if (array[mid] == x)
            return mid;

        // Search the right half
        if (array[mid] < x)
            return binarySearch1(array, x, low, mid - 1);

        // Search the left half
        return binarySearch1(array, x, mid + 1, high);
    }

    return -1;
}

int binarySearch(int* arr, int size, int toFind, unsigned long long& C) {
    return binarySearch1(arr, toFind, 0, size - 1);
}

#endif
