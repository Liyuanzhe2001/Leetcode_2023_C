//
// Created by LiYuanzhe on 2023/12/31.
//
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        vector<int> add = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int res = day;
        for (int i = 0; i < month - 1; i++) {
            res += add[i];
        }
        if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
            res++;
        }
        return res;
    }
};
