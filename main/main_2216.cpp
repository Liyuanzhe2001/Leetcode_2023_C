//
// Created by LiYuanzhe on 2023/11/21.
//
#include "vector"

using namespace std;

class Solution {
public:
    int minDeletion(vector<int> &nums) {
        int pre = -1;
        int n = 0;
        int s = 0;
        for (int num: nums) {
            if (n % 2 == 0) {
                pre = num;  
                n++;
            } else {
                if (num != pre) {
                    n++;
                    s++;
                }
            }
        }

        return nums.size() - 2 * s;
    }
};
