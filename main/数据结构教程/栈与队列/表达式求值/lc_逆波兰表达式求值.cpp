//
// Created by LiYuanzhe on 2023/9/6.
//

#include "stack"
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<string> s;
        for (const auto &c: tokens) {
            if (isNumber(c)) {
                s.emplace(c);
            } else {
                int n1 = stoi(s.top());
                s.pop();
                int n2 = stoi(s.top());
                s.pop();
                int n = 0;
                switch (c[0]) {
                    case '+':
                        n = n1 + n2;
                        break;
                    case '-':
                        n = n2 - n1;
                        break;
                    case '*':
                        n = n1 * n2;
                        break;
                    case '/':
                        n = n2 / n1;
                        break;
                }
                s.emplace(to_string(n));
            }
        }
        return stoi(s.top());
    }
    bool isNumber(string token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};
