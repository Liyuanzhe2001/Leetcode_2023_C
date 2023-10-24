//
// Created by LiYuanzhe on 2023/10/23.
//
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        int res = 0;
        int n = points.size();
        vector<bool> visited(n, false);
        visited[0] = true;

        int minIndex = -1;
        int minVal = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                
            }
        }
    }
};
