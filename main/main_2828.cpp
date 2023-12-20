//
// Created by LiYuanzhe on 2023/12/20.
//
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    bool isAcronym(vector<string> &words, string s) {
        if (s.size() != words.size()) {
            return false;
        }
        for (int i = 0; i < words.size(); i++) {
            if (s[i] != words[i][0]) {
                return false;
            }
        }
        return true;
    }
};
