/**
    LeetCode_88
    https://leetcode.com/problems/merge-sorted-array/description/
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = (int) nums1.size() - 1;
        int i = m - 1;
        int j = n - 1;
        while (last >= 0) {
            if (i >= 0 && j >= 0) {
                if (nums1[i] < nums2[j]) {
                    nums1[last--] = nums2[j--];
                } else {
                    nums1[last--] = nums1[i--];
                }
            } else if (i >= 0) {
                nums1[last--] = nums1[i--];
            } else {
                nums1[last--] = nums2[j--];
            }
        }
    }
};

int main() {
    return 0;
}
