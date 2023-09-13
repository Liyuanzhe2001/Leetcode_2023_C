//
// Created by LiYuanzhe on 2023/9/13.
//
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    int compress(vector<char> &chars) {
        int len = 1;
        int index = 1;
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == chars[i - 1]) {
                len++;
            } else {
                if (len != 1) {
                    string tmp = to_string(len);
                    for (auto c: tmp) {
                        chars[index++] = c;
                    }
                }
                chars[index++] = chars[i];
                len = 1;
            }
        }
        if (len != 1) {
            string tmp = to_string(len);
            for (auto c: tmp) {
                chars[index++] = c;
            }
        }
        return index;
    }
};