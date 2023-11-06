//
// Created by LiYuanzhe on 2023/11/7.
//
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    int vowelStrings(vector<string> &words, int left, int right) {
        int res = 0;
        string w = "aeiou";
        for (int i = left; i <= right; i++) {
            if (w.find(words[i][0]) != string::npos && w.find(words[i].back()) != string::npos) {
                res++;
            }
        }
        return res;
    }
};
