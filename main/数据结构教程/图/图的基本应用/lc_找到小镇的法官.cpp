//
// Created by LiYuanzhe on 2023/10/9.
//
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>> &trust) {
        vector<bool> ts(n + 1);
        vector<int> bts(n + 1);
        for (const auto &item: trust) {
            ts[item[0]] = true;
            bts[item[1]]++;
        }
        for (int i = 1; i < n + 1; i++) {
            if (bts[i] == n - 1 && !ts[i]) {
                return i;
            }
        }
        return -1;
    }
};
