//
// Created by LiYuanzhe on 2023/10/16.
//
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        unordered_map<int, int> map;
        for (const auto &num: nums) {
            map[num]++;
        }
        vector<int> res;
        for (const auto &p: map) {
            if (p.second == 2) {
                res.emplace_back(p.first);
            }
        }
        return res;
    }
};
