//
// Created by LiYuanzhe on 2023/9/26.
//

class Solution {
public:
    int passThePillow(int n, int time) {
        time %= (n - 1) * 2;
        return time < n ? time + 1 : n * 2 - time - 1;
    }
};
