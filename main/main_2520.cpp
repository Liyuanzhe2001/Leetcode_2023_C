//
// Created by LiYuanzhe on 2023/10/26.
//
#include "string"

using namespace std;

class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        string str = to_string(num);
        for (const auto &item: str) {
            if (num % (item - '0') == 0) {
                res++;
            }
        }
        return res;
    }
};
