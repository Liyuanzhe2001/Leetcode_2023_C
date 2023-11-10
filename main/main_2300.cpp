//
// Created by LiYuanzhe on 2023/11/10.
//
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (auto &i: spells) {
            long long t = (success + i - 1) / i - 1;
            res.push_back(potions.size() - (upper_bound(potions.begin(), potions.end(), t) - potions.begin()));
        }
        return res;
    }
};