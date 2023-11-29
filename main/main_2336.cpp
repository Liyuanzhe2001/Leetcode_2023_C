//
// Created by LiYuanzhe on 2023/11/29.
//
#include "set"

using namespace std;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
    }

    int popSmallest() {
        if (s.empty()) {
            return minVal;
        }
        int res = *s.begin();
        s.erase(res);
        return res;
    }

    void addBack(int num) {
        s.emplace(num);
    }

private:
    int minVal = 1;
    set<int> s;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
