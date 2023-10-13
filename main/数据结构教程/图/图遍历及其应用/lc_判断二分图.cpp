//
// Created by LiYuanzhe on 2023/10/13.
//
#include "vector"
#include "queue"

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        for (int k = 0; k < n; k++) {
            if (visited[k] == 0) {
                queue<int> q;
                q.emplace(0);
                visited[0] = 1;
                while (!q.empty()) {
                    int s = q.size();
                    for (int i = 0; i < s; i++) {
                        int node = q.front();
                        q.pop();
                        for (const auto &item: graph[node]) {
                            if (visited[item] == visited[node]) {
                                return false;
                            }
                            if (visited[item] == 0) {
                                q.emplace(item);
                            }
                            visited[item] = -visited[node];
                        }
                    }
                }
            }
        }
        return true;
    }
};