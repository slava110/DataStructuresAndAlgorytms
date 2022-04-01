#include <iostream>
#include "arrayio.h"
#include "lib.h"

using namespace std;

int main() {
    int type;
    cout << "Select array type (1 - static, 2 - dynamic, 3 - vector): " << endl;
    do {
        cout << ">";
        cin >> type;
        if(!cin.fail() && type > 0 && type < 4)
            break;
        cout << "Wrong input! Expected number between 1 and 3" << endl;
    } while (true);

    if(type == 1) {
        int size = 5;
        cout << "You've chosen static array so array length automatically set to 5" << endl;
        int arr[5];

        cout << "Enter array elements (" << size << "):" << endl;
        cout << ">";
        arrInput(arr, size);

        int primeIndex = task0_static::findPrime(arr, size);

        int* afterIns;
        if(primeIndex != -1) {
            std::cout << "Prime number found at index " << primeIndex << std::endl;

            std::cout << "Inserting 69 into array at index after primeIndex" << std::endl;
            afterIns = task0_static::arrInsert(arr, size, primeIndex + 1, 69);
            std::cout << "Result array: " << std::endl;
            arrOutput(afterIns, size);
        } else {
            std::cout << "Prime number not found!" << std::endl;
            afterIns = arr;
        }

        int resSize = 0;

        int* resArr = task0_static::arrDelete(afterIns, size, resSize);
        if(resSize > 0) {
            std::cout << "Removed all numbers by condition" << std::endl;
            std::cout << "Result array: " << std::endl;
            arrOutput(resArr, resSize);
        } else {
            std::cout << "Removed all numbers by condition and result array is empty" << std::endl;
        }
    } else if(type == 2) {
        cout << "You've chosen dynamic array" << endl;
        int size;
        cout << "Set array size:" << endl;
        cout << ">";
        cin >> size;

        int* arr = new int[size];

        cout << "Enter array elements (" << size << "):" << endl;
        cout << ">";
        arrInput(arr, size);

        int primeIndex = task0_dynamic::findPrime(arr, size);

        if(primeIndex != -1) {
            std::cout << "Prime number found at index " << primeIndex << std::endl;

            std::cout << "Inserting 69 into array at index after primeIndex" << std::endl;
            task0_dynamic::arrInsert(arr, size, primeIndex + 1, 69);
            std::cout << "Result array: " << std::endl;
            arrOutput(arr, size);
        } else {
            std::cout << "Prime number not found!" << std::endl;
        }

        int resSize = 0;

        int* resArr = task0_dynamic::arrDelete(arr, size, resSize);
        if(resSize > 0) {
            std::cout << "Removed all numbers by condition" << std::endl;
            std::cout << "Result array: " << std::endl;
            arrOutput(resArr, resSize);
        } else {
            std::cout << "Removed all numbers by condition and result array is empty" << std::endl;
        }
    } else if(type == 3) {
        cout << "You've chosen vector" << endl;
        int size;
        cout << "Set vector size:" << endl;
        cout << ">";
        cin >> size;

        vector<int> arr(size);

        cout << "Enter array elements (" << size << "):" << endl;
        cout << ">";
        task0_vector::vecInput(arr);

        int primeIndex = task0_vector::findPrime(arr);

        if(primeIndex != -1) {
            std::cout << "Prime number found at index " << primeIndex << std::endl;

            std::cout << "Inserting 69 into array at index after primeIndex" << std::endl;
            task0_vector::arrInsert(arr, primeIndex + 1, 69);
            std::cout << "Result array: " << std::endl;
            task0_vector::vecOutput(arr);
        } else {
            std::cout << "Prime number not found!" << std::endl;
        }

        if(task0_vector::arrDelete(arr)) {
            std::cout << "Removed all numbers by condition" << std::endl;
            std::cout << "Result array: " << std::endl;
            task0_vector::vecOutput(arr);
        } else {
            std::cout << "Removed all numbers by condition and result array is empty" << std::endl;
        }
    }
}