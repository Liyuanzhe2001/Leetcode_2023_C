//
// Created by LiYuanzhe on 2023/9/11.
//

#include "iostream"
#include "string"

using namespace std;

bool composition(string s1, string s2);

int main() {
    cout << composition("ababab", "ab") << endl;
    return 0;
}

bool composition(string s1, string s2) {
    int index = 0;
    while (index < s1.size()) {
        if (s1.substr(index, s2.size()) != s2) {
            return false;
        }
        index += s2.size();
    }
    return true;
}