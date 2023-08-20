//
// Created by LiYuanzhe on 2023/8/20.
//
#include "iostream"
#include "algorithm"
#include "unordered_set"

using namespace std;

class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> set;
        int i = 1;
        int res = 0;
        while (set.size() < n) {
            if (!set.count(k - i)) {
                set.insert(i);
                res += i;
            }
            i++;
        }
        return res;
    }
};
