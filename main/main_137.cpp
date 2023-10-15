//
// Created by LiYuanzhe on 2023/10/15.
//
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> map;
        for (const auto &item: nums) {
            map[item]++;
        }
        for (const auto &item: map) {
            if (item.second != 3) {
                return item.first;
            }
        }
        return 0;
    }
};
