#ifndef DSAA_LIBVECTOR_H
#define DSAA_LIBVECTOR_H
#include <vector>
#include "libCommon.h"

namespace task0_vector {
    void vecInput(vector<int> arr) {
        for (int i = 0; i < arr.size(); i++) { // NOLINT(modernize-loop-convert)
            cin >> arr[i];
        }
    }

    void vecOutput(vector<int> arr) {
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i];
            if(i < arr.size() - 1)
                cout << ", ";
            else
                cout << endl;
        }
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
}
#endif //DSAA_LIBVECTOR_H
