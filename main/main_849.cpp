//
// Created by LiYuanzhe on 2023/8/22.
//
#include "algorithm"

using namespace std;


class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {
        int lef = -1;
        int res = 0;
        int len = seats.size();
        for (int i = 0; i < len; i++) {
            if (seats[i] == 1) {
                if (lef == -1) {
                    res = i;
                } else {
                    res = max(res, (i - lef) >> 1);
                }
                lef = i;
            }
        }
        res = max(res, len - lef - 1);
        return res;
    }
};
