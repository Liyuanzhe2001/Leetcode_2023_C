//
// Created by LiYuanzhe on 2023/9/13.
//

#include "string"

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        char startC = s[0];
        int len = s.size();
        for (int i = 1; i < len / 2; i++) {
            if (s[i] == startC && len % i == 0) {
                if (composition(s, s.substr(0, i))) {
                    return true;
                }
            }
        }
        return false;
    }

    bool composition(string s1, string s2) {
        int index = 0;
        while (index < s1.size()) {
            if (s1.substr(index, s2.size()) != s2) {
                return false;
            }
            index += s2.size();
        }
        return true;
    }

};
