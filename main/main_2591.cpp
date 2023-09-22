//
// Created by LiYuanzhe on 2023/9/22.
//
#include "algorithm"

using namespace std;

class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }
        money -= children;
        int res = min(money / 7, children);
        money -= res * 7;
        children -= res;

        if ((children == 0 && money != 0) || (children == 1 && money == 3)) {
            return res - 1;
        }
        return res;
    }
};