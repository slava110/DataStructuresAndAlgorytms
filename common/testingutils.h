#ifndef DSAA_TESTINGUTILS_H
#define DSAA_TESTINGUTILS_H
#include <functional>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

void arrRandomize(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand(); // NOLINT(cert-msc50-cpp)
    }
}

unsigned long measureTime(const function<void ()>& block) {
    auto start = high_resolution_clock::now();
    block();
    auto stop = high_resolution_clock::now();
    return duration_cast<milliseconds>(stop - start).count();
}

/**
 * Test sort function. Measure execution time, amount of comparisons, amount of modifications
 * @param sortFunc sorting function to test
 * @param elementsAmount amount of randomly generated elements
 */
void testSort(const std::function<void (int*, int, unsigned long long&, unsigned long long&)> sortFunc, const int elementsAmount) {
    int* arr = new int[elementsAmount];

    arrRandomize(arr, elementsAmount);

    unsigned long long C = 0;
    unsigned long long M = 0;

    unsigned long time = measureTime([&]() {
        sortFunc(arr, elementsAmount, C, M);
    });

    cout << "Measured execution time: " << time << " ms" << endl;
    cout << "Measured comparison ops amount: " << C << endl;
    cout << "Measured modification ops amount: " << M << endl;

    //arrOutput(arr, size);

    delete[] arr;
}
#endif //DSAA_TESTINGUTILS_H
