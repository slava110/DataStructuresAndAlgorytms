#include <iostream>

using namespace std;

#include "singlylinkedlist.h"
#include "buslist.h"

void testSinglyLinked() {

}

void testDoublyLinked() {

}

int main() {
    cout << "Linked List Implementation" << endl;
    cout << "What do you want to test? (1 - singly-linked-list, 2 - doubly-linked-list)" << endl;
    int choice;
    do {
        cin >> choice;
    } while (cin.fail() || choice < 1 || choice > 2);

    if(choice == 1)
        testSinglyLinked();
    else
        testDoublyLinked();
}