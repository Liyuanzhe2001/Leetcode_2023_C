//
// Created by LiYuanzhe on 2023/10/25.
//
#include "string"

using namespace std;

class Solution {
public:

    bool dfs(string str, int idx, int sum, int target) {
        if (idx == str.size()) {
            return sum == target;
        }
        int add = 0;
        for (int i = idx; i < str.size(); i++) {
            add = add * 10 + (str[i] - '0');
            if (sum + add > target) {
                return false;
            }
            if (dfs(str, i + 1, sum + add, target)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (dfs(to_string(i * i), 0, 0, i)) {
                res += i;
            }
        }
        return res;
    }
};
