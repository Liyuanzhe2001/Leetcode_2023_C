//
// Created by LiYuanzhe on 2023/9/11.
//
#include "vector"

using namespace std;


class MyCircularQueue {
public:

    vector<int> queue;
    int front;
    int rear;
    int size;

    MyCircularQueue(int k) {
        queue.resize(k);
        size = k;
        front = 0;
        rear = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        queue[front % size] = value;
        front++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        rear++;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return queue[front % size];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return queue[rear % size];
    }

    bool isEmpty() {
        return rear == front;
    }

    bool isFull() {
        return rear - front >= size;
    }
};
