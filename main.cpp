#include <iostream>

// Basic functions
int* createArray(int size);
void arrInput(int* arr, int size);
void arrOutput(int* arr, int size);

// Helper functions
bool isPrime(int num);

// Task implementation
int findPrime(int* arr, int size);
void arrInsert(int*& arr, int& size, int index, int value);
int* arrDelete(const int* arr, int size, int &resSize);


int main() {
    int size = 5;
    int* arr = createArray(size);

    arrInput(arr, size);

    int primeIndex = findPrime(arr, size);
    if(primeIndex != -1) {
        std::cout << "Prime number found at index " << primeIndex << std::endl;

        std::cout << "Inserting 69 into array at index after primeIndex" << std::endl;
        arrInsert(arr, size, primeIndex + 1, 69);
        std::cout << "Result array: " << std::endl;
        arrOutput(arr, size);
    } else {
        std::cout << "Prime number not found!" << std::endl;
    }

    int resSize = 0;

    int* resArr = arrDelete(arr, size, resSize);
    if(resSize > 0) {
        std::cout << "Removed all numbers by condition" << std::endl;
        std::cout << "Result array: " << std::endl;
        arrOutput(resArr, resSize);
    } else {
        std::cout << "Removed all numbers by condition and result array is empty" << std::endl;
    }
}

int* createArray(int size) {
    return new int[size];
}

void arrInput(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
}

void arrOutput(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }
}

bool isPrime(int num) {
    if(num < 2) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;
    for(int i=3; (i*i)<=num; i+=2){
        if(num % i == 0 ) return false;
    }
    return true;
}

int findPrime(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        if(isPrime(arr[i]))
            return i;
    }
    return -1;
}

void arrInsert(int*& arr, int& size, int index, int value) {
    arr = static_cast<int *>(realloc(arr, (size + 1) * sizeof(int)));
    size++;
    // Shift elements
    for (int i = size - 1; i >= index; --i) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
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