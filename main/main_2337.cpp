//
// Created by LiYuanzhe on 2023/8/21.
//

/*
 * public boolean canChange(String start, String target) {
        int startIndex = 0;
        char[] charArray = target.toCharArray();
        for (int i = 0, charArrayLength = charArray.length; i < charArrayLength; i++) {
            char c = charArray[i];
            if (c != '_') {
                while (startIndex < start.length() && start.charAt(startIndex) == '_') {
                    startIndex++;
                }
                if ((startIndex == start.length()) ||
                        (start.charAt(startIndex) != c) ||
                        (c == 'L' && i > startIndex) ||
                        (c == 'R' && i < startIndex)) {
                    return false;
                }
                startIndex++;
            }
        }
        for (int i = startIndex; i < start.length(); i++) {
            if (start.charAt(i) != '_') {
                return false;
            }
        }
        return true;
    }
 */

#include "iostream"

using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int startIndex = 0;
        for (int i = 0; i < target.size(); i++) {
            char c = target[i];
            if (c != '_') {
                while (startIndex < start.length() && start[startIndex] == '_') {
                    startIndex++;
                }
                if ((startIndex == start.length()) ||
                    (start[startIndex] != c) ||
                    (c == 'L' && i > startIndex) ||
                    (c == 'R' && i < startIndex)) {
                    return false;
                }
                startIndex++;
            }
        }
        for (int i = startIndex; i < start.length(); i++) {
            if (start[i] != '_') {
                return false;
            }
        }
        return true;
    }
};
