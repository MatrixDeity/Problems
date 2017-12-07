/**
    LeetCode_33
    https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;

        int n = (int) nums.size();
        int i = 0, j = n - 1;
        while (i < j) {
            int m = i + (j - i) / 2;
            if (nums[m] > nums[j])
                i = m + 1;
            else
                j = m;
        }
        int r = i;
        i = 0;
        j = n - 1;
        while (i <= j) {
            int m = i + (j - i) / 2;
            int rm = (r + m) % n;
            if (nums[rm] == target)
                return rm;
            if (target > nums[rm])
                i = m + 1;
            else
                j = m - 1;
        }
        return -1;
    }
};

int main() {
    return 0;
}
