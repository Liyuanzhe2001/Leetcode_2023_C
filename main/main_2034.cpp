//
// Created by LiYuanzhe on 2023/10/8.
//

#include "unordered_map"
#include "set"

using namespace std;

class StockPrice {
public:

    int maxTime;
    unordered_map<int, int> map;
    multiset<int> prices;

    StockPrice() {
        maxTime = -1;
    }

    void update(int timestamp, int price) {
        maxTime = max(maxTime, timestamp);
        if (map.count(timestamp)) {
            prices.erase(prices.find(map[timestamp]));
        }
        prices.emplace(price);
        map[timestamp] = price;
    }

    int current() {
        return map[maxTime];
    }

    int maximum() {
        return *prices.rbegin();
    }

    int minimum() {
        return *prices.begin();
    }
};
