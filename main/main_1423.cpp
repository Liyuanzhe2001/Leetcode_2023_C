//
// Created by LiYuanzhe on 2023/12/3.
//
#include "vector"

using namespace std;

class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int n = cardPoints.size();
        int res = 0;
        for (int i = 0; i < k; i++) {
            res += cardPoints[i];
        }
        int tmp = res;
        for (int i = k - 1; i >= 0; i--) {
            res = max(res, tmp = tmp - cardPoints[i] + cardPoints[n - k + i]);
        }
        return res;
    }
};