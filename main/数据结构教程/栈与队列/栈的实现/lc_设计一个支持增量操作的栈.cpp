//
// Created by LiYuanzhe on 2023/8/30.
//

#include "iostream"
#include "algorithm"

using namespace std;


class CustomStack {
public:

    vector<int> stack;
    int top;

    CustomStack(int maxSize) {
        stack.resize(maxSize);
        top = -1;
    }

    void push(int x) {
        if (top != stack.size() - 1) {
            ++top;
            stack[top] = x;
        }
    }

    int pop() {
        if (top == -1) {
            return -1;
        }
        --top;
        return stack[top + 1];
    }

    void increment(int k, int val) {
        int lim = min(k, top + 1);
        for (int i = 0; i < lim; ++i) {
            stack[i] += val;
        }
    }
};