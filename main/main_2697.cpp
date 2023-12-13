//
// Created by LiYuanzhe on 2023/12/13.
//
#include "string"

using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] > s[j]) {
                s[j] = s[i];
            } else {
                s[i] = s[j];
            }
        }
        return s;
    }
};