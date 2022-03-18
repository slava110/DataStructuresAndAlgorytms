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