//
// Created by LiYuanzhe on 2023/9/11.
//

#include "queue"

using namespace std;

class MyStack {
public:

    queue<int> stk;
    queue<int> tmpStk;

    MyStack() {

    }

    void push(int x) {
        while (!stk.empty()) {
            tmpStk.emplace(stk.front());
            stk.pop();
        }
        stk.emplace(x);
        while (!tmpStk.empty()) {
            stk.emplace(tmpStk.front());
            tmpStk.pop();
        }
    }

    int pop() {
        int res = stk.front();
        stk.pop();
        return res;
    }

    int top() {
        return stk.front();
    }

    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
