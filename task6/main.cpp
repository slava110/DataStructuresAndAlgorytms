#include "lib.h"
#include "ui.h"
#include <fstream>

string readFile(const std::string& path) {
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '" << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    return {(std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>()};
}

int main() {
    cout << "Testing KMP text search with UI" << endl;

    string path;
    cout << "Enter text file path:" << endl;
    cout << ">" << endl;
    cin >> path;

    string toFind;
    cout << "Enter string to find:" << endl;
    cout << ">" << endl;
    cin >> toFind;

    cout << "Searching..." << endl;

    int index;
    unsigned long long C;
    unsigned long long M;

    unsigned long long time = measureTime([&](){
        index = searchKMP(readFile(path), toFind, C, M);
    });

    if(index != -1) {
        cout << "Found string at index " << index << endl;
    } else {
        cout << "String not found in provided text!" << endl;
    }

    cout << "Comparisons: " << C << endl;
    cout << "Shifts: " << M << endl;
}