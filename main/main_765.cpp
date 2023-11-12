////
//// Created by LiYuanzhe on 2023/11/11.
////
//#include "vector"
//
//using namespace std;
//
//class UnionFind {
//private:
//    vector<int> parents;
//    int count;
//public:
//    UnionFind(int n) {
//        for (int i = 0; i < n; i++) {
//            parents.emplace_back(i);
//        }
//        count = n;
//    }
//
//    int Find(int x) {
//        if (parents[x] == x) {
//            return x;
//        }
//        return parents[x] = Find(parents[x]);
//    }
//
//    void Union(int x, int y) {
//        int rx = Find(x), ry = Find(y);
//        if (rx != ry) {
//            parents[ry] = rx;
//            count--;
//        }
//    }
//
//    int GetCount() {
//        return count;
//    }
//
//};
//
//class Solution {
//public:
//    int minSwapsCouples(vector<int> &row) {
//        UnionFind uf(row.size() / 2);
//        for (int i = 0; i < row.size(); i += 2) {
//            uf.Union(row[i] / 2, row[i + 1] / 2);
//        }
//        return row.size() / 2 - uf.GetCount();
//    }
//};