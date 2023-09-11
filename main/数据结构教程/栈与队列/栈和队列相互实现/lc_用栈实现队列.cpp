//
// Created by LiYuanzhe on 2023/9/11.
//
#include "stack"

using namespace std;

class MyQueue {
public:

    stack<int> stk;
    stack<int> tmpStk;

    MyQueue() {

    }

    void push(int x) {
        stk.push(x);
    }

    int pop() {
        while (!stk.empty()) {
            tmpStk.emplace(stk.top());
            stk.pop();
        }
        int res = tmpStk.top();
        tmpStk.pop();
        while (!tmpStk.empty()) {
            stk.emplace(tmpStk.top());
            tmpStk.pop();
        }
        return res;
    }

    int peek() {
        while (!stk.empty()) {
            tmpStk.emplace(stk.top());
            stk.pop();
        }
        int res = tmpStk.top();
        while (!tmpStk.empty()) {
            stk.emplace(tmpStk.top());
            tmpStk.pop();
        }
        return res;
    }

    bool empty() {
        return stk.empty();
    }
};