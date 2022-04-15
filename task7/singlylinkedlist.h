/**
 * @brief Singly-linked-list implementation
 */
#ifndef DSAA_SINGLYLINKEDLIST_H
#define DSAA_SINGLYLINKEDLIST_H

#include <functional>
using namespace std;

class SinglyLinkedList {
    struct Node {
        int data;
        Node* next;

        Node(int data, Node* next): data(data), next(next) {}
    };

    Node* head = nullptr;
public:

    void put(int data) {
        head = new Node(data, head);
    }

    void forEach(const function<void (int)>& func) {
        Node* cur = head;
        while (cur != nullptr) {
            func(cur->data);
            cur = cur->next;
        }
    }

    bool contains(int data) {
        Node* cur = head;
        while (cur != nullptr) {
            if(cur->data == data)
                return true;
            cur = cur->next;
        }
        return false;
    }

    /**
     * @brief Combine with different linked list and return new list containing elements from both lists
     * @param other
     * @return
     */
    SinglyLinkedList* combineWith(SinglyLinkedList* other) {
        auto* res = new SinglyLinkedList();
        forEach([res](int el){
            res->put(el);
        });
        other->forEach([res, this](int el){
            if(!this->contains(el))
                res->put(el);
        });
        return res;
    }
};

#endif //DSAA_SINGLYLINKEDLIST_H
