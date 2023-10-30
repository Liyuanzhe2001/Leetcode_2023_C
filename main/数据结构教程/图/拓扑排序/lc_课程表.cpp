//
// Created by LiYuanzhe on 2023/10/30.
//
#include "vector"
#include "queue"

using namespace std;

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> index;

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        index.resize(numCourses);
        for (const auto &info: prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++index[info[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (index[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0;
        while (!q.empty()) {
            ++visited;
            int u = q.front();
            q.pop();
            for (int v: edges[u]) {
                --index[v];
                if (index[v] == 0) {
                    q.push(v);
                }
            }
        }

        return visited == numCourses;
    }
};