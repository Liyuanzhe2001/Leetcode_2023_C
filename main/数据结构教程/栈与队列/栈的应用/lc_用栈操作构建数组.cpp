//
// Created by LiYuanzhe on 2023/9/4.
//
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int> &target, int n) {
        vector<string> res;
        for (int i = 1, t = 0; i <= n && t < target.size(); i++) {
            if (target[t] == i) {
                res.emplace_back("Push");
                t++;
            } else {
                res.emplace_back("Push");
                res.emplace_back("Pop");
            }
        }
        return res;
    }
};