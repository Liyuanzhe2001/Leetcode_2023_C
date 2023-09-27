//
// Created by LiYuanzhe on 2023/9/27.
//
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:

    vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> tmp;
        for (auto restaurant : restaurants) {
            if ((!veganFriendly || restaurant[2]) && maxPrice <= restaurant[3] && maxDistance <= restaurant[4]) {
                tmp.emplace_back(restaurant);
            }
        }
        sort(tmp.begin(), tmp.end(), [](vector<int> v1, vector<int> v2) {
            if (v1[1] > v2[1]) {
                return false;
            } else if (v1[1] == v2[1]) {
                return true;
            } else {
                if (v1[1] > v2[1]) {
                    return false;
                } else {
                    return true;
                }
            }
        });

        vector<int> res;
        for (const auto &item: tmp) {
            res.emplace_back(item[0]);
        }

        return res;
    }
};
