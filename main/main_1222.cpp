//
// Created by LiYuanzhe on 2023/9/14.
//

#include "vector"
#include "cstring"

using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king) {
        int distance[8][2] = {{0,  1},
                              {1,  0},
                              {0,  -1},
                              {-1, 0},
                              {1,  1},
                              {1,  -1},
                              {-1, 1},
                              {-1, -1}};
        int map[8][8];
        memset(map, 0, sizeof(map));
        for (const auto &queen: queens) {
            map[queen[0]][queen[1]] = 1;
        }
        vector<vector<int>> res;
        for (const auto &item: distance) {
            int x = king[0];
            int y = king[1];
            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (map[x][y] == 1) {
                    res.push_back({x, y});
                    break;
                }
                x += item[0];
                y += item[1];
            }
        }
        return res;
    }
};
