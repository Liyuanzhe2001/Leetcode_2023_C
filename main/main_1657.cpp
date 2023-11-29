//
// Created by LiYuanzhe on 2023/11/30.
//
#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> count1(26), count2(26);
        for (char c: word1) {
            count1[c - 'a']++;
        }
        for (char c: word2) {
            count2[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if ((count1[i] != 0 && count2[i] == 0) || (count1[i] == 0 && count2[i] != 0)) {
                return false;
            }
        }
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());
        for (int i = 0; i < 26; i++) {
            if (count1[i] != count2[i]) {
                return false;
            }
        }
        return true;
    }
};
