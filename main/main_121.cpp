//
// Created by LiYuanzhe on 2023/10/1.
//

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minV = prices[0];
        int profit = 0;
        for (const auto &price: prices) {
            if (price - minV < 0) {
                minV = price;
            } else {
                profit = max(profit, price - minV);
            }
        }
        return profit;
    }
};
