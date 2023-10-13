//
// Created by LiYuanzhe on 2023/10/13.
//

#include "vector"
#include "queue"

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        int step = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                pair<int, int> plc = q.front();
                q.pop();
            }
        }
    }
};
