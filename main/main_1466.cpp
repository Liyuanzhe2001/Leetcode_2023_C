//
// Created by LiYuanzhe on 2023/12/7.
//
#include "vector"

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>> &connections) {
        vector<vector<pair<int, int> >> roads(n);
        for (vector<int> connection: connections) {
            roads[connection[0]].emplace_back(connection[1], 1);
            roads[connection[1]].emplace_back(connection[0], 0);
        }
        return dfs(-1, 0, roads);
    }

    int dfs(int fa, int idx, vector<vector<pair<int, int>>> &roads) {
        int res = 0;
        for (auto [cityNo, isPoint]: roads[idx]) {
            if (cityNo != fa) {
                res += isPoint + dfs(idx, cityNo, roads);
            }
        }
        return res;
    }
};