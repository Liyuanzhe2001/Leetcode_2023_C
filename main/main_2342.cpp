//
// Created by LiYuanzhe on 2023/11/18.
//
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int maximumSum(vector<int> &nums) {
        unordered_map<int, int> map;
        int res = -1;
        for (int num: nums) {
            int n = 0;
            int tmp = num;
            while (num) {
                n += num % 10;
                num /= 10;
            }
            if (map.count(n)) {
                res = max(res, map[n] + tmp);
            }
            map[n] = max(map[n], tmp);
        }
        return res;
    }
};