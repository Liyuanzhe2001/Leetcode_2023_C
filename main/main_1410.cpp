//
// Created by LiYuanzhe on 2023/11/23.
//
#include "string"
#include "unordered_map"

using namespace std;

class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, char> map;
        map["&quot;"] = '"';
        map["&apos;"] = '\'';
        map["&amp;"] = '&';
        map["&gt;"] = '>';
        map["&lt;"] = '<';
        map["&frasl;"] = '/';
        string tmp = "";
        string res = "";
        for (char c: text) {
            if (c == '&') {
                if (!tmp.empty()) {
                    res.append(tmp);
                }
                tmp = '&';
            } else if (c == ';') {
                tmp += ';';
                if (map.count(tmp)) {
                    tmp = map[tmp];
                }
                res.append(tmp);
                tmp = "";
            } else {
                tmp += c;
            }
        }
        res.append(tmp);
        return res;
    }
};
