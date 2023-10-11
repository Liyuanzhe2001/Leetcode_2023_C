//
// Created by LiYuanzhe on 2023/10/11.
//
#include "sstream"
#include "vector"
#include "string"
#include "iostream"
#include "unordered_map"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<int>
    topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report,
                vector<int> &student_id, int k) {
        unordered_map<string, int> words;
        for (const auto &item: positive_feedback) {
            words[item] = 3;
        }
        for (const auto &item: negative_feedback) {
            words[item] = -1;
        }

        vector<pair<int, int>> A;
        for (int i = 0; i < report.size(); i++) {
            stringstream ss;
            string w;
            int score = 0;
            ss << report[i];
            while (ss >> w) {
                if (words.count(w)) {
                    score += words[w];
                }
            }
            A.emplace_back(student_id[i], score);
        }

        sort(A.begin(), A.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.emplace_back(A[i].first);
        }

        return res;
    }
};
