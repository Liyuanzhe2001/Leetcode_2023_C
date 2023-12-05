//
// Created by LiYuanzhe on 2023/12/5.
//
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
        int n = roads.size();
        throughs.resize(n + 1);
        for (const auto &road: roads) {
            throughs[road[0]].emplace_back(road[1]);
            throughs[road[1]].emplace_back(road[0]);
        }
        dfs(0, -1, seats);
        return res;
    }

    int dfs(int cur, int pre, int seats) {
        int peopleSum = 1;
        for (auto ne: throughs[cur]) {
            if (ne != pre) {
                int peopleCnt = dfs(ne, cur, seats);
                peopleSum += peopleCnt;
                res += (peopleCnt + seats - 1) / seats;
            }
        }
        return peopleSum;
    }

private:
    vector<vector<int>> throughs;
    long long res = 0;
};
