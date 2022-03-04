#include <iostream>
#include <vector>

// Basic functions
std::vector<int> createArray(int size);
void arrInput(std::vector<int>& arr);
void arrOutput(std::vector<int>& arr);

// Helper functions
bool isPrime(int num);

// Task implementation
int findPrime(std::vector<int>& arr);
void arrInsert(std::vector<int>& arr, int index, int value);
bool arrDelete(std::vector<int>& arr);


int main() {
    int size = 5;
    std::vector<int> arr = createArray(size);

    arrInput(arr);

    int primeIndex = findPrime(arr);
    if(primeIndex != -1) {
        std::cout << "Prime number found at index " << primeIndex << std::endl;

        std::cout << "Inserting 69 into array at index after primeIndex" << std::endl;
        arrInsert(arr, primeIndex + 1, 69);
        std::cout << "Result array: " << std::endl;
        arrOutput(arr);
    } else {
        std::cout << "Prime number not found!" << std::endl;
    }

    if(arrDelete(arr)) {
        std::cout << "Removed all numbers by condition" << std::endl;
        std::cout << "Result array: " << std::endl;
        arrOutput(arr);
    } else {
        std::cout << "Removed all numbers by condition and result array is empty" << std::endl;
    }
}

std::vector<int> createArray(int size) {
    return std::vector<int>(size);
}

void arrInput(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cin >> arr[i];
    }
}

void arrOutput(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
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

int findPrime(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        if(isPrime(arr[i]))
            return i;
    }
    return -1;
}

void arrInsert(std::vector<int>& arr, int index, int value) {
    arr.insert(arr.begin() + index, value);
}

bool arrDelete(std::vector<int>& arr) {
    bool res = false;
    for(auto it = arr.begin(); it != arr.end(); ++it) {
        if(*it % 7 == 0) {
            arr.erase(it);
            --it;
            res = true;
        }
    }
    return res;
}