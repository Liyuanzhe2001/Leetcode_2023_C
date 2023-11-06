//
// Created by LiYuanzhe on 2023/11/6.
//
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    int maxProduct(vector<string> &words) {
        vector<int> b(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                b[i] |= 1 << (words[i][j] - 'a');
            }
        }
        int res = 0;
        for (int i = 0; i < b.size(); i++) {
            for (int j = i + 1; j < b.size(); j++) {
                if ((b[i] & b[j]) == 0) {
                    res = max(res, (int) (words[i].length() * words[j].length()));
                }
            }
        }
        return res;
    }
};
