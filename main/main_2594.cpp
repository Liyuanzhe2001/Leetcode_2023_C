//
// Created by LiYuanzhe on 2023/9/7.
//
#include "vector"
#include "iostream"
#include "algorithm"
#include "cmath"

using namespace std;

class Solution {
public:
    long long repairCars(vector<int> &ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        long long lef = 1;
        long long rig = 1ll * ranks[ranks.size() - 1] * cars * cars;
        while (lef <= rig) {
            long long mid = (lef + rig) >> 1;
            long long tmpSum = 0;
            for (int rank: ranks) {
                tmpSum += (long long) sqrt(mid / rank);
            }
            cout << mid << " " << tmpSum << endl;
            if (tmpSum < cars) {
                lef = mid + 1;
            } else {
                rig = mid - 1;
            }
        }
        return lef;
    }
};