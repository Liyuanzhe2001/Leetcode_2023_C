//
// Created by LiYuanzhe on 2023/10/27.
//
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
        long long e = 1e9 + 1;
        horizontalCuts.emplace_back(h);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        long long maxH = 0, preH = 0;
        for (const auto &item: horizontalCuts) {
            maxH = max(maxH, item - preH);
            preH = item;
        }
        verticalCuts.emplace_back(w);
        sort(verticalCuts.begin(),verticalCuts.end());
        long long maxW = 0, preW = 0;
        for (const auto &item: verticalCuts) {
            maxW = max(maxW, item - preW);
            preW = item;
        }
        return maxH * maxW % e;
    }
};