//
// Created by LiYuanzhe on 2023/9/20.
//

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n = 0;
        int res = n;
        for (int num: nums) {
            if (num) {
                n++;
            } else {
                res = max(n, res);
                n = 0;
            }
        }
        return max(n, res);
    }
};
