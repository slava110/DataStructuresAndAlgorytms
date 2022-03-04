#include <iostream>

// Basic functions
void arrInput(int* arr, int size);
void arrOutput(int* arr, int size);

// Helper functions
bool isPrime(int num);

// Task implementation
int findPrime(int* arr, int size);
int* arrInsert(const int* arr, int& size, int index, int value);
int* arrDelete(const int* arr, int size, int &resSize);


int main() {
    int size = 5;
    int arr[5];

    arrInput(arr, size);

    int* resArr;
    int primeIndex = findPrime(arr, size);
    if(primeIndex != -1) {
        std::cout << "Prime number found at index " << primeIndex << std::endl;

        std::cout << "Inserting 69 into array at index after primeIndex" << std::endl;
        resArr = arrInsert(arr, size, primeIndex + 1, 69);
        std::cout << "Result array: " << std::endl;
        arrOutput(resArr, size);
    } else {
        resArr = arr;
        std::cout << "Prime number not found!" << std::endl;
    }

    int resSize = 0;

    int* resArr2 = arrDelete(resArr, size, resSize);
    if(resSize > 0) {
        std::cout << "Removed all numbers by condition" << std::endl;
        std::cout << "Result array: " << std::endl;
        arrOutput(resArr2, resSize);
    } else {
        std::cout << "Removed all numbers by condition and result array is empty" << std::endl;
    }
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