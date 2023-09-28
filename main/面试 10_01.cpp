//
// Created by LiYuanzhe on 2023/9/28.
//
#include "vector"

using namespace std;

class Solution {
public:
    void merge(vector<int> &A, int m, vector<int> &B, int n) {
        int index = m + n - 1;
        int indexA = m - 1;
        int indexB = n - 1;
        while (index >= 0) {
            if (indexA == -1) {
                A[index] = B[indexB--];
            } else if (indexB == -1) {
                A[index] = A[indexA--];
            } else {
                if (A[indexA] > B[indexB]) {
                    A[index] = B[indexB--];
                } else {
                    A[index] = A[indexA--];
                }
            }
            index--;
        }
    }
};
