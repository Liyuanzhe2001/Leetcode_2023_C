//
// Created by LiYuanzhe on 2023/11/5.
//
#include "string"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> m;
        string str = s.substr(0, 10);
        m[str]++;
        for (int i = 10; i < s.length(); i++) {
            str.erase(0, 1);
            str += s[i];
            m[str]++;
        }
        vector<string> res;
        for (const auto &[key, val]: m) {
            if (val >= 2) {
                res.emplace_back(key);
            }
        }
        return res;
    }
};
