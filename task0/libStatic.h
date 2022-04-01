#ifndef DSAA_LIBSTATIC_H
#define DSAA_LIBSTATIC_H
#include <iostream>
#include "libCommon.h"

namespace task0_static {

    int findPrime(int* arr, int size) {
        for (int i = 0; i < size; ++i) {
            if(isPrime(arr[i]))
                return i;
        }
        return -1;
    }

    int* arrInsert(const int* arr, int& size, int index, int value) {
        size++;
        int* res = new int[size];
        // Shift elements
        for (int i = 0; i < size - 1; ++i) {
            res[i >= index ? i + 1 : i] = arr[i];
        }
        res[index] = value;
        return res;
    }

    int* arrDelete(const int* arr, int size, int& resSize) {
        int* res = new int[0];

        for (int i = 0; i < size; ++i) {
            if(arr[i] % 7 != 0) {
                if(resSize == 0) {
                    res = new int[1];
                } else {
                    res = static_cast<int*>(realloc(res, (resSize + 1) * sizeof(int)));
                }
                res[resSize] = arr[i];
                resSize++;
            }
        }
        return resSize > 0 ? res : nullptr;
    }
}

#endif
