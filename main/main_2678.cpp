//
// Created by LiYuanzhe on 2023/10/23.
//
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int countSeniors(vector<string> &details) {
        int res = 0;
        for (const auto &detail: details) {
            if (stoi(detail.substr(12, 13)) > 60) {
                res++;
            }
        }
        return res;
    }
};
