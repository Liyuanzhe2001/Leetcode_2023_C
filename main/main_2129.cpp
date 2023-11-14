//
// Created by LiYuanzhe on 2023/11/14.
//
#include <sstream>
#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss(title);
        string item;
        string res = "";
        while (getline(ss, item, ' ')) {
            transform(item.begin(), item.end(), item.begin(), ::tolower);
            if (item.length() > 2) {
                item[0] = item[0] - 'a' + 'A';
            }
            res.append(item).append(" ");
        }
        res.erase(res.end());
        return res;
    }
};