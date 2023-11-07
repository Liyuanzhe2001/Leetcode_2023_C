//
// Created by LiYuanzhe on 2023/11/8.
//
#include "string"

using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int res = 0;
        int lenZ = 0;
        int lenO = 0;
        for (const auto &c: s) {
            if (c == '0') {
                if (lenO) {
                    lenZ = 1;
                    lenO = 0;
                } else {
                    lenZ++;
                }
            } else {
                lenO++;
            }
            res = max(2 * min(lenO, lenZ), res);
        }
        return res;
    }
};
