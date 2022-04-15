#include <iostream>
#include <sstream>

using namespace std;

#include "stringutils.h"
#include "singlylinkedlist.h"
#include "buslist.h"

void testSinglyLinked() {
    cout << "Enter first list elements:" << endl;

    auto* list1 = new SinglyLinkedList();

    string n;
    cin.clear();
    while (getline(cin, n, '\n') && n != "-") {
        list1->put(stoi(n));
    }

    cout << "Enter second list elements:" << endl;

    auto* list2 = new SinglyLinkedList();

    cin.clear();
    while (getline(cin, n, '\n') && n != "-") {
        list2->put(stoi(n));
    }

    SinglyLinkedList* list3 = list1->combineWith(list2);

    cout << "Combined: " << endl;

    list3->forEach([](int el){
        cout << el<< endl;
    });

    delete list1;
    delete list2;
    delete list3;
}

void testDoublyLinked() {
    cout << "Add bus elements. Format: `<bus number> <route id> <departure date> <departure time> <cost>`:" << endl;

    auto* list = new BusInfoList();

    string rawEl;

    int busNum;
    string routeId;
    string depDate;
    int depTime;
    int cost;

    cin.clear();
    while (getline(cin, rawEl, '\n') && rawEl != "-") {
        stringstream bss(rawEl);
        bss >> busNum >> ' ' >> routeId >> ' ' >> depDate >> ' ' >> depTime >> ' ' >> cost;

    }

    cout << "Bus list:" << endl;
    list->forEach([](BusInfo* info) {
        cout << "[" << info->busNum << "] on route (" << info->routeId << ") will departure in " << info->depDate << " at " << info->depTime << ". Cost: " << info->cost << endl;
    });
    cout << "Bus list reversed:" << endl;
    list->forEachReversed([](BusInfo* info) {
        cout << "[" << info->busNum << "] on route (" << info->routeId << ") will departure in " << info->depDate << " at " << info->depTime << ". Cost: " << info->cost << endl;
    });
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