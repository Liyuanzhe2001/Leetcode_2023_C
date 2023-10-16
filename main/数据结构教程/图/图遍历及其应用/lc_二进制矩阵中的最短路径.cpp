//
// Created by LiYuanzhe on 2023/10/13.
//

#include "vector"
#include "queue"

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector <vector<int>> &grid) {
        if (grid[0][0] == 1) {
            return -1;
        }

        int distance[8][2] = {{1,  0},
                              {-1, 0},
                              {0,  1},
                              {0,  -1},
                              {-1, -1},
                              {-1, 1},
                              {1,  -1},
                              {1,  1}};

        queue <pair<int, int>> q;
        q.emplace(0, 0);
        int res = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                pair<int, int> plc = q.front();
                q.pop();
                int x = plc.first;
                int y = plc.second;
                if (x < 0 || x >= grid.size() || y < 0 || y >= grid.size() || grid[x][y] == 1) {
                    continue;
                }
                if (x == grid.size() - 1 && y == grid.size() - 1) {
                    return res + 1;
                }
                grid[x][y] = 1;
                for (const auto &d: distance) {
                    q.emplace(x + d[0], y + d[1]);
                }
            }
            res++;
        }
        return -1;
    }
};
