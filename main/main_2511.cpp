//
// Created by LiYuanzhe on 2023/9/2.
//

#include "algorithm"

using namespace std;

class Solution {
public:
    int captureForts(vector<int> &forts) {
        int pre = -1;
        int res = 0;
        for (int i = 0; i < forts.size(); i++) {
            if (forts[i] != 0) {
                if (pre != -1 && forts[i] == -forts[pre]) {
                    res = max(res, i - pre - 1);
                }
                pre = i;
            }
        }
        return res;
    }
};
