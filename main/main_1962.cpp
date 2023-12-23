//
// Created by LiYuanzhe on 2023/12/23.
//
#include "queue"

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int> &piles, int k) {
        priority_queue<int> pq;
        int sum = 0;
        for (int &pile: piles) {
            pq.emplace(pile);
            sum += pile;
        }
        for (int i = 0; i < k; i++) {
            int tmp = pq.top();
            pq.pop();
            sum -= tmp / 2;
            tmp -= tmp / 2;
            pq.emplace(tmp);
        }
        return sum;
    }
};
