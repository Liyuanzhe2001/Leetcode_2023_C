//
// Created by LiYuanzhe on 2023/11/26.
//
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int>> map;
        for (int i = 0; i < s.size(); i++) {
            map[s[i]].emplace_back(i);
        }
        int res = 0;
        for (auto &[_, arr]: map) {
            arr.insert(arr.begin(), -1);
            arr.emplace_back(s.size());
            for (int i = 1; i < s.size() - 1; i++) {
                res += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
            }
        }
        return res;
    }
};