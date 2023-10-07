//
// Created by LiYuanzhe on 2023/10/7.
//

#include "string"

using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        int a = -1, b = -1, n = s.size(), c[26] = {0}, ds = 0;
        for (int i = 0; i < n; ++i) {
            if (++c[s[i] - 'a'] == 2) {
                ds = true;
            }
            if (s[i] != goal[i]) {
                if (b == -1) {
                    a = s[i], b = goal[i];
                } else if (a != goal[i] || b != s[i]) {
                    return false;
                } else {
                    a = -1;
                }
            }
        }
        return a == -1 && (b != -1 || ds);
    }
};