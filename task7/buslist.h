/**
 * @brief Doubly-linked-list implementation. Each node contains info about certain bus
 */
#ifndef DSAA_DOUBLYLINKEDLIST_H
#define DSAA_DOUBLYLINKEDLIST_H

#include <iostream>
#include <functional>
#include <utility>
using namespace std;

/**
 * @brief Struct for doubly-linked-list node
 */
struct BusInfo {
    int busNum;
    string routeId;
    int depTime;
    string depDate;
    int cost;
    BusInfo* prev;
    BusInfo* next;

    BusInfo(
            int busNum,
            string routeId,
            int depTime,
            string depDate,
            int cost,
            BusInfo* prev,
            BusInfo* next
    ): busNum(busNum), routeId(std::move(routeId)), depTime(depTime), depDate(std::move(depDate)), cost(cost), prev(prev), next(next) {}

    // Not sure if I should do this in destructor or separate method...
    ~BusInfo() {
        prev->next = next;
    }

    // We're overriding << operator for fancy output c:
    friend ostream& operator<<(ostream& stream, const BusInfo& busInfo) {
        stream << "Bus number: " << busInfo.busNum << endl;
        stream << "Route ID: " << busInfo.routeId << endl;
        stream << "Departure date: " << busInfo.depDate << " at " << busInfo.depTime << endl;
        stream << "Cost: " << busInfo.cost;
        return stream;
    }
};

/**
 * @brief Doubly linked list with bus information
 */
class BusInfoList {
    BusInfo* head = nullptr;
    BusInfo* tail = nullptr;
public:

    void put(const int busNum, const string& routeId, const int depTime, const string& depDate, const int cost) {
        head = new BusInfo(busNum, routeId, depTime, depDate, cost, head, tail);
        if(tail == nullptr)
            tail = head;
    }

    void forEach(const function<void (BusInfo*)>& func) {
        BusInfo* cur = head;
        while (cur != nullptr) {
            func(cur);
            cur = cur->next;
        }
    }

    void forEachReversed(const function<void (BusInfo*)>& func) {
        BusInfo* cur = tail;
        while (cur != nullptr) {
            func(cur);
            cur = cur->prev;
        }
    }

    void printFromStart() {
        forEach([](BusInfo* busInfo){
            cout << busInfo << endl;
        });
    }

    void printFromEnd() {
        forEachReversed([](BusInfo* busInfo){
            cout << busInfo << endl;
        });
    }

    /**
     * @brief Find certain BusInfo by predicate. Yes, I'm in love with Kotlin
     * @param predicate condition
     * @return BusInfo matching given predicate or nullptr
     */
    BusInfo* find(const function<bool (BusInfo*)>& predicate) {
        BusInfo* cur = head;
        while (cur != nullptr && !predicate(cur)) {
            cur = cur->next;
        }
        return cur;
    }
};


#endif //DSAA_DOUBLYLINKEDLIST_H
