//
// Created by LiYuanzhe on 2023/10/19.
//
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int> &nums) {
        int res = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                map[nums[i] * nums[j]]++;
            }
        }
        for (const auto &item: map) {
            res += item.second * (item.second - 1) * 4;
        }
        return res;
    }
};