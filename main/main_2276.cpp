////
//// Created by LiYuanzhe on 2023/12/16.
////
//// TODO 2276
//#include "map"
//
//using namespace std;
//
//class CountIntervals {
//    map<int, int> m;
//    int cnt = 0; // 所有区间长度和
//
//public:
//    CountIntervals() {}
//
//    void add(int left, int right) {
//        // 遍历所有被 [left,right] 覆盖到的区间（部分覆盖也算）
//        for (auto it = m.lower_bound(left); it != m.end() && it->second <= right; m.erase(it++)) {
//            int l = it->second, r = it->first;
//            left = min(left, l);   // 合并后的新区间，其左端点为所有被覆盖的区间的左端点的最小值
//            right = max(right, r); // 合并后的新区间，其右端点为所有被覆盖的区间的右端点的最大值
//            cnt -= r - l + 1;
//        }
//        cnt += right - left + 1;
//        m[right] = left; // 所有被覆盖到的区间与 [left,right] 合并成一个新区间
//    }
//
//    int count() { return cnt; }
//};