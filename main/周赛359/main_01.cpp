//
// Created by LiYuanzhe on 2023/8/20.
//
#include "iostream"
#include "algorithm"

using namespace std;


class Solution {
public:
    bool isAcronym(vector<string> &words, string s) {
        if (s.size() != words.size()) {
            return false;
        }
        string str = "";
        for (const auto &item: words) {
            str += (item[0]);
        }
        return str == s;
    }
};


