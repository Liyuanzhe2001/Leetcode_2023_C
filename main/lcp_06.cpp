//
// Created by LiYuanzhe on 2023/9/20.
//

#include "vector"

using namespace std;

class Solution {
public:
    int minCount(vector<int> &coins) {
        int res = 0;
        for (const auto &item: coins) {
            res += (item + 1) >> 1;
        }
        return res;
    }
};
