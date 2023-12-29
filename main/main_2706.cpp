//
// Created by LiYuanzhe on 2023/12/29.
//
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int buyChoco(vector<int> &prices, int money) {
        int fi = INT_MAX, se = INT_MAX;
        for (auto p: prices) {
            if (p < fi) {
                se = fi;
                fi = p;
            } else if (p < se) {
                se = p;
            }
        }
        return money < fi + se ? money : money - fi - se;
    }
};
