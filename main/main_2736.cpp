//
// Created by LiYuanzhe on 2023/11/17.
//
#include "vector"
#include "algorithm"
#include "numeric"

using namespace std;

class Solution {
public:
    vector<int> maximumSumQueries(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries) {
        vector<pair<int, int>> a(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            a[i] = {nums1[i], nums2[i]};
        }
        sort(a.begin(), a.end(),
             [](auto &a, auto &b) { return a.first > b.first; });

        vector<int> qid(queries.size());
        iota(qid.begin(), qid.end(), 0);
        sort(qid.begin(), qid.end(),
             [&](int i, int j) { return queries[i][0] > queries[j][0]; });

        vector<int> ans(queries.size());
        vector<pair<int, int>> st;
        int j = 0;
        for (int i: qid) {
            int x = queries[i][0], y = queries[i][1];
            for (; j < a.size() && a[j].first >= x; j++) { // 下面只需关心 a[j].second
                while (!st.empty() && st.back().second <= a[j].first + a[j].second) { // a[j].second >= st.back().first
                    st.pop_back();
                }
                if (st.empty() || st.back().first < a[j].second) {
                    st.emplace_back(a[j].second, a[j].first + a[j].second);
                }
            }
            auto it = lower_bound(st.begin(), st.end(), y,
                                  [](const auto &p, int val) { return p.first < val; });
            ans[i] = it != st.end() ? it->second : -1;
        }
        return ans;
    }
};