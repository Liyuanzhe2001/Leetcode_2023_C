//
// Created by LiYuanzhe on 2023/9/29.
//
#include "vector"

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int pre = 0;
        int res = 0;
        for (const auto &flower: flowerbed) {
            if (!flower && !pre) {
                res++;
                pre = 1;
            } else if (flower && pre) {
                res--;
                pre = 1;
            } else {
                pre = flower;
            }
            if (res >= n) {
                return true;
            }
        }
        return false;
    }
};
