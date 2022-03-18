#ifndef DSAA_LIB_H
#define DSAA_LIB_H
void insertionSort(int* arr, int size) {
    int i, j, temp;

    for (i = 0; i < size; ++i) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void insertionSortTest(int* arr, int size, int& C, int& M) {
    int i, j, temp;

    for (i = 0; i < size; ++i) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            C++;
            arr[j + 1] = arr[j];
            M++;
            j--;
        }
        C++;
        arr[j + 1] = temp;
        M++;
    }
}
#endif
