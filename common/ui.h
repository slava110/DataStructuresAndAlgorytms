#ifndef DSAA_UI_H
#define DSAA_UI_H
#include <iostream>
#include <string>
#include <functional>
#include <sstream>
#include <chrono>
#include "arrayio.h"

using namespace std;
using namespace std::chrono;

int* arrayInputAdv(int& size) {
    srand(time(nullptr)); // NOLINT(cert-msc51-cpp)

    if(size == 0) {
        cout << "Enter amount of elements to sort:" << endl << ">";
        cin >> size;
    }

    int* arr = new int[size];

    cout << "Enter elements:" << endl << ">";
    string input;
    cin.ignore();
    getline(cin, input, '\n');

    int i = 0;

    if(!input.empty()) {
        stringstream inputStream(input);
        string rawNum;

        while (i < size && !inputStream.eof()) {
            getline(inputStream, rawNum, ' ');
            if(input.empty())
                break;

            try {
                int num = stoi(rawNum);
                arr[i] = num;
                i++;
            } catch(std::invalid_argument const& ex) {
                cout << "Invalid number (" << ex.what() << ")" << endl;
            } catch(std::out_of_range const& ex) {
                cout << "Number out of range (" << ex.what() << ")" << endl;
            }
        }
    }

    if(i == 0) {
        cout << "No elements entered. Generating random array..." << endl;
        arrRandomize(arr, size);
        cout << "Generated random array: ";
        arrOutput(arr, size);
    } else if(i < size) {
        cout << "Not all elements entered. " << size - i << " elements will be randomized then" << endl;
        for(; i < size; i++) {
            arr[i] = rand(); // NOLINT(cert-msc50-cpp)
        }
    }
    return arr;
}

unsigned long long measureTime(const function<void ()>& block) {
    auto start = high_resolution_clock::now();
    block();
    auto stop = high_resolution_clock::now();
    return duration_cast<milliseconds>(stop - start).count();
}

/**
 *
 * @param name
 * @param sortFunc `func(array: int[], arraySize: int, comparsions: ULL reference, modifications: ULL reference`
 */
void testSortWithUI(const string& name, const function<void (int*, int, unsigned long long&, unsigned long long&)>& sortFunc) {
    cout << "Testing " << name << " with UI" << endl;

    int size = 0;
    int* arr = arrayInputAdv(size);

    cout << "Sorting..." << endl;

    unsigned long long comparisons = 0;
    unsigned long long modifications = 0;
    unsigned long long time = measureTime([&]{
        sortFunc(arr, size, comparisons, modifications);
    });

    cout << "Array sorted" << endl;
    cout << "- Sorting time: " << time << "ms" << endl;
    cout << "- Comparisons: " << comparisons << ", modifications: " << modifications << endl;
    cout << "- Result array: ";
    arrOutput(arr, size);

    delete[] arr;
}

/**
 *
 * @param name
 * @param searchFunc `func(array: int[], arraySize: int, toFind: int, comparisons: ULL reference, modifications: ULL reference`
 */
void testSearchWithUI(const string& name, const function<void (int*, int, unsigned long long&, unsigned long long&)>& searchFunc) {
    cout << "Testing " << name << " with UI" << endl;

    int size = 0;
    int* arr = arrayInputAdv(size);

    cout << "Enter number to find:";
    int toFind;
    cin >> toFind;

    cout << "Searching for " << toFind << " in array..." << endl;

    unsigned long long comparisons = 0;
    unsigned long long modifications = 0;
    unsigned long long time = measureTime([&]{
        searchFunc(arr, size, comparisons, modifications);
    });

    cout << "Array sorted" << endl;
    cout << "- Sorting time: " << time << "ms" << endl;
    cout << "- Comparisons: " << comparisons << ", modifications: " << modifications << endl;
    cout << "- Result array: ";
    arrOutput(arr, size);

    delete[] arr;
}
#endif //DSAA_UI_H
