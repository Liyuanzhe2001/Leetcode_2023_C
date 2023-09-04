#include "string"
#include "stack"

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                if (stk.empty()) {
                    s.erase(i, 1);
                    i--;
                } else {
                    stk.pop();
                }
            }
        }
        while (!stk.empty()) {
            s.erase(stk.top(), 1);
            stk.pop();
        }
        return s;
    }
};

