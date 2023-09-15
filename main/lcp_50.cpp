//
// Created by LiYuanzhe on 2023/9/15.
//
#include "vector"

using namespace std;

class Solution {
public:
    int giveGem(vector<int> &gem, vector<vector<int>> &operations) {
        for (const auto &ope: operations) {
            int n = gem[ope[0]] / 2;
            gem[ope[0]] -= n;
            gem[ope[1]] += n;
        }
        int maxV = gem[0];
        int minV = gem[0];
        for (const auto &item: gem) {
            maxV = max(maxV, item);
            minV = min(minV, item);
        }
        return maxV - minV;
    }
};
