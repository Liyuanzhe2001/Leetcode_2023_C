//
// Created by LiYuanzhe on 2023/12/2.
//
#include "vector"

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        int n = 0;
        for (vector<int> trip: trips) {
            n = max(trip[2], n);
        }
        vector<int> passengers(n + 1);
        for (vector<int> trip: trips) {
            passengers[trip[1]] += trip[0];
            passengers[trip[2]] -= trip[0];
        }
        int tmp = 0;
        for (int passenger: passengers) {
            tmp += passenger;
            if (tmp > capacity) {
                return false;
            }
        }
        return true;
    }
};
