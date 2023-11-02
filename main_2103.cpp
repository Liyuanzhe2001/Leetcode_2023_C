//
// Created by LiYuanzhe on 2023/11/2.
//
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        vector<int> no(10, 0);
        for (int i = 0; i < rings.size(); i += 2) {
            if (rings[i] == 'B') {
                no[rings[i + 1] - '0'] |= 1;
            } else if (rings[i] == 'G') {
                no[rings[i + 1] - '0'] |= 2;
            } else {
                no[rings[i + 1] - '0'] |= 4;
            }
        }
        int res = 0;
        for (const auto &n: no) {
            res += n == 7 ? 1 : 0;
        }
        return res;
    }
};
