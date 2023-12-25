//
// Created by LiYuanzhe on 2023/12/25.
//
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (tomatoSlices < 2 * cheeseSlices) {
            return {};
        }
        int total_jumbo = (tomatoSlices - 2 * cheeseSlices) / 2;
        int total_small = cheeseSlices - total_jumbo;
        if (total_jumbo < 0 || total_small < 0 || total_jumbo * 4 + total_small * 2 != tomatoSlices) {
            return {};
        }
        return {total_jumbo, total_small};
    }
};
