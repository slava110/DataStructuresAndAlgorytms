#ifndef DSAA_LIB_H
#define DSAA_LIB_H

#include <algorithm>

// Merge two subarrays X and Z into arr
void merge(int* arr, int start, int middle, int end, unsigned long long& C, unsigned long long& M) {
    // Create X ← A[start..middle] and Z ← A[middle+1..end]
    int n1 = middle - start + 1;
    int n2 = end - middle;

    int X[n1], Z[n2];

    for (int i = 0; i < n1; i++) {
        X[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++)
        Z[j] = arr[middle + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    // Until we reach either end of either X or Z, pick larger among
    // elements X and Z and place them in the correct position at A[start..end]
    while (i < n1 && j < n2) {
        if (X[i] <= Z[j]) {
            arr[k] = X[i];
            i++;
        } else {
            arr[k] = Z[j];
            j++;
        }
        M++;
        C++;
        k++;
    }

    // When we run out of elements in either X or Z,
    // pick up the remaining elements and put in A[start..end]
    while (i < n1) {
        arr[k] = X[i];
        M++;
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = Z[j];
        M++;
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort1(int* arr, int start, int end, unsigned long long& C, unsigned long long& M) { // NOLINT(misc-no-recursion)
    if (start < end) {
        // middle is the point where the array is divided into two subarrays
        int middle = start + (end - start) / 2;

        mergeSort1(arr, start, middle, C, M);
        mergeSort1(arr, middle + 1, end, C, M);

        // Merge the sorted subarrays
        merge(arr, start, middle, end, C, M);
    }
}

void mergeSort(int* arr, int size, unsigned long long& C, unsigned long long& M) {
    mergeSort1(arr, 0, size - 1, C, M);
}
#endif //DSAA_LIB_H
