#ifndef DSAA_LIB_H
#define DSAA_LIB_H
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int* arr, int size) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < size-1; i++){
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < size; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

void selectionSortTest(int* arr, int size, unsigned long long& C, unsigned long long& M) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < size-1; i++){
        C++;
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < size; j++) {
            C++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
            C++;
        }

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
        M+=2;
    }
}
#endif //DSAA_LIB_H
