//
// Created by LiYuanzhe on 2023/10/11.
//
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    long long findTheArrayConcVal(vector<int> &nums) {
        long long res = 0;
        int lef = 0;
        int rig = nums.size() - 1;
        while (lef <= rig) {
            if (lef == rig) {
                res += nums[lef];
            } else {
                res += stoi(to_string(nums[lef]) + to_string(nums[rig]));
            }
            lef++;
            rig--;
        }
        return res;
    }
};