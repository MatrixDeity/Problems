/**
    LeetCode_350
    https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Just for fun let's assume arrays already is sorted
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int n = (int) nums1.size();
        int m = (int) nums2.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i;
                ++j;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                ++i;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
