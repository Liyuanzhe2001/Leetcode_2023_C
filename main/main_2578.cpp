//
// Created by LiYuanzhe on 2023/10/9.
//
#include "set"

using namespace std;

class Solution {
public:

    int splitNum(int num) {
        multiset<int> s;
        while (num) {
            s.emplace(num % 10);
            num /= 10;
        }
        int num1 = 0;
        int num2 = 0;
        bool b = true;
        while (!s.empty()) {
            if (b) {
                num1 *= 10;
                num1 += *s.begin();
            } else {
                num2 *= 10;
                num2 += *s.begin();
            }
            s.erase(s.begin());
            b = !b;
        }
        return num1 + num2;
    }
};