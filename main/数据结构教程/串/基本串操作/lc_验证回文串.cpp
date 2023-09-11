//
// Created by LiYuanzhe on 2023/9/11.
//

#include "string"

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int lef = 0;
        int rig = s.length() - 1;
        while (lef < rig) {
            while (lef < s.length() && !isdigit(s[lef]) && ('a' > tolower(s[lef]) || tolower(s[lef]) > 'z')) {
                lef++;
            }
            while (rig >= 0 && !isdigit(s[lef]) && ('a' > tolower(s[rig]) || tolower(s[rig]) > 'z')) {
                rig--;
            }
            if (lef < s.length() && rig >= 0 && tolower(s[lef]) != tolower(s[rig])) {
                return false;
            }
            lef++;
            rig--;
        }
        return true;
    }
};

