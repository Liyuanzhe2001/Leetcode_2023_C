//
// Created by LiYuanzhe on 2023/8/31.
//
#include "stack"
#include "algorithm"

using namespace std;

class MinStack {
public:

    stack<int> stk;
    stack<int> minStk;

    MinStack() {
    }

    void push(int val) {
        int minVal = val;
        if (!minStk.empty()) {
            minVal = min(minStk.top(), val);
        }
        minStk.push(minVal);
        stk.push(val);
    }

    void pop() {
        minStk.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
};
