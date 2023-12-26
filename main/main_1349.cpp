////
//// Created by LiYuanzhe on 2023/12/26.
////
//// TODO 1349
//#include "vector"
//#include "algorithm"
//
//using namespace std;
//
//// 会超时的递归代码
////class Solution {
////public:
////    int maxStudents(vector<vector<char>> &seats) {
////        int m = seats.size(), n = seats[0].size();
////        vector<int> a(m); // a[i] 是第 i 排可用椅子的下标集合
////        for (int i = 0; i < m; i++) {
////            for (int j = 0; j < n; j++) {
////                if (seats[i][j] == '.') {
////                    a[i] |= 1 << j;
////                }
////            }
////        }
////
////        function<int(int, int)> dfs = [&](int i, int j) -> int {
////            if (i == 0) {
////                if (j == 0) {
////                    return 0;
////                }
////                int lb = j & -j;
////                return dfs(i, j & ~(lb * 3)) + 1;
////            }
////            int res = dfs(i - 1, a[i - 1]); // 第 i 排空着
////            for (int s = j; s; s = (s - 1) & j) { // 枚举 j 的子集 s
////                if ((s & (s >> 1)) == 0) { // s 没有连续的 1
////                    int t = a[i - 1] & ~(s << 1 | s >> 1); // 去掉不能坐人的位置
////                    res = max(res, dfs(i - 1, t) + __builtin_popcount(s));
////                }
////            }
////            return res;
////        };
////        return dfs(m - 1, a[m - 1]);
////    }
////};
//class Solution {
//public:
//    int maxStudents(vector<vector<char>> &seats) {
//        int m = seats.size(), n = seats[0].size();
//        vector<int> a(m); // a[i] 是第 i 排可用椅子的下标集合
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (seats[i][j] == '.') {
//                    a[i] |= 1 << j;
//                }
//            }
//        }
//
//        vector<vector<int>> memo(m, vector<int>(1 << n, -1)); // -1 表示没有计算过
//        function<int(int, int)> dfs = [&](int i, int j) -> int {
//            int &res = memo[i][j]; // 注意这里是引用
//            if (res != -1) { // 之前计算过
//                return res;
//            }
//            if (i == 0) {
//                if (j == 0) {
//                    return res = 0;
//                }
//                int lb = j & -j;
//                return res = dfs(i, j & ~(lb * 3)) + 1;
//            }
//            res = dfs(i - 1, a[i - 1]); // 第 i 排空着
//            for (int s = j; s; s = (s - 1) & j) { // 枚举 j 的子集 s
//                if ((s & (s >> 1)) == 0) { // s 没有连续的 1
//                    int t = a[i - 1] & ~(s << 1 | s >> 1); // 去掉不能坐人的位置
//                    res = max(res, dfs(i - 1, t) + __builtin_popcount(s));
//                }
//            }
//            return res;
//        };
//        return dfs(m - 1, a[m - 1]);
//    }
//};
