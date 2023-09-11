//
// Created by LiYuanzhe on 2023/9/11.
//
#include "vector"
#include "cmath"
#include "deque"

using namespace std;

class MyCircularDeque {
public:

    deque<int> deq;
    int len;

    MyCircularDeque(int k) {
        len = k;
    }

    bool insertFront(int value) {
        if (deq.size() >= len) return false;
        deq.push_front(value);
        return true;
    }

    bool insertLast(int value) {
        if (deq.size() >= len) return false;
        deq.push_back(value);
        return true;
    }

    bool deleteFront() {
        if (deq.empty()) return false;
        deq.pop_front();
        return true;
    }

    bool deleteLast() {
        if (deq.empty()) return false;
        deq.pop_back();
        return true;
    }

    int getFront() {
        if (deq.empty()) return -1;
        return deq.front();
    }

    int getRear() {
        if (deq.empty()) return -1;
        return deq.back();
    }

    bool isEmpty() {
        return deq.empty();
    }

    bool isFull() {
        return deq.size() >= len;
    }
};
