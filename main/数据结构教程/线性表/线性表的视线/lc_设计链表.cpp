#include "algorithm"

using namespace std;

class LinkedList {
public:
    int val;
    LinkedList *next;

    LinkedList(int val) {
        this->val = val;
    }

    LinkedList() = default;

};

class MyLinkedList {
public:

    LinkedList *head;

    MyLinkedList() {
        this->head = new LinkedList(0);
    }

    int get(int index) {
        if (index < 0 || index >= head->val) {
            return -1;
        }
        return findNode(index)->next->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(head->val, val);
    }

    void addAtIndex(int index, int val) {
        if (index > head->val) {
            return;
        }
        head->val++;
        index = max(0, index);
        LinkedList *pred = findNode(index);
        LinkedList *toAdd = new LinkedList(val);
        toAdd->next = pred->next;
        pred->next = toAdd;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= head->val) {
            return;
        }
        head->val--;
        LinkedList *pred = findNode(index);
        LinkedList *p = pred->next;
        pred->next = pred->next->next;
        delete p;
    }

    LinkedList *findNode(int index) {
        LinkedList *pred = head;
        for (int i = 0; i < index; i++) {
            pred = pred->next;
        }
        return pred;
    }

};