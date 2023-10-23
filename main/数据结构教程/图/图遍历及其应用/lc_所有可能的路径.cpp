//
// Created by LiYuanzhe on 2023/10/23.
//
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        n = graph.size();
        dfs(graph, vector<int>(), 0);
        return res;
    }

    void dfs(vector<vector<int>> graph, vector<int> way, int index) {
        way.emplace_back(index);
        if (index == n - 1) {
            res.emplace_back(way);
            return;
        }
        for (const auto &nextIndex: graph[index]) {
            dfs(graph, way, nextIndex);
        }
    }

private:
    vector<vector<int>> res;
    int n;
};