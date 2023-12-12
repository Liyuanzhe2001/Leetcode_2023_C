////
//// Created by LiYuanzhe on 2023/12/12.
////
//#include "vector"
//
//using namespace std;
//
//class Solution {
//public:
//    vector<int> secondGreaterElement(vector<int> &nums) {
//        int n = nums.size();
//        vector<int> ans(n, -1), s, t;
//        for (int i = 0; i < n; i++) {
//            int x = nums[i];
//            while (!t.empty() && nums[t.back()] < x) {
//                ans[t.back()] = x; // t 栈顶的下下个更大元素是 x
//                t.pop_back();
//            }
//            int j = s.size();
//            while (j && nums[s[j - 1]] < x) {
//                j--; // s 栈顶的下一个更大元素是 x
//            }
//            t.insert(t.end(), s.begin() + j, s.end()); // 把从 s 弹出的这一整段元素加到 t
//            s.resize(j); // 弹出一整段元素
//            s.push_back(i); // 当前元素（的下标）加到 s 栈顶
//        }
//        return ans;
//    }
//};
