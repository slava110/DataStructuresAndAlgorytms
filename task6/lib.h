#ifndef DSAA_LIB_H
#define DSAA_LIB_H

#include <iostream>

// Function to implement the KMP algorithm
int searchKMP(std::string text, std::string pattern, unsigned long long& C, unsigned long long& M) {
    int m = text.length();
    int n = pattern.length();

    // if pattern is an empty string
    if (n == 0) {
        return 0;
    }

    // if text's length is less than that of pattern's
    if (m < n){
        return -1;
    }

    // next[i] stores the index of the next best partial match
    int next[n + 1];

    for (int i = 0; i < n + 1; i++) {
        next[i] = 0;
    }

    for (int i = 1; i < n; i++){
        int j = next[i + 1];

        while (j > 0 && pattern[j] != pattern[i]) {
            C++;
            j = next[j];
        }

        if (j > 0 || pattern[j] == pattern[i]) {
            C++;
            next[i + 1] = j + 1;
            M++;
        }
    }

    for (int i = 0, j = 0; i < m; i++){
        C++;
        if (text[i] == pattern[j]){
            C++;
            if (++j == n) {
                return i - j + 1;
            }
        } else if (j > 0) {
            j = next[j];
            i--;    // since `i` will be incremented in the next iteration
        }
    }
    return -1;
}

#endif
