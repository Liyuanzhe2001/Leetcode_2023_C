//
// Created by LiYuanzhe on 2023/10/25.
//
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (const auto &edge: edges) {
            if (Find(parent, edge[0]) != Find(parent, edge[1])) {
                Union(parent, edge[0], edge[1]);
            } else {
                return {edge[0], edge[1]};
            }
        }
        return {};
    }

    int Find(vector<int> &parent, int index) {
        if (parent[index] != index) {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }

    void Union(vector<int> &parent, int index1, int index2) {
        parent[Find(parent, index1)] = Find(parent, index2);
    }

};