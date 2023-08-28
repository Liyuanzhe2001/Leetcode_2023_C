//
// Created by LiYuanzhe on 2023/8/28.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> res;

        for (const auto &interval: intervals) {
            if (interval[0] > right) {
                if (!placed) {
                    res.push_back({left, right});
                    placed = true;
                }
                res.push_back(interval);
            } else if (interval[1] < left) {
                res.push_back(interval);
            } else {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            res.push_back({left, right});
        }
        return res;
    }
};