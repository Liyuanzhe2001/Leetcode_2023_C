//
// Created by LiYuanzhe on 2023/10/30.
//
#include "vector"

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int lef = 0;
        int rig = citations.size() - 1;
        while (lef < rig) {
            int mid = (lef + rig) >> 1;
            if (citations[mid] >= citations.size() - mid) {
                rig = mid - 1;
            } else {
                lef = mid + 1;
            }
        }
        return citations.size() - lef;
    }
};
