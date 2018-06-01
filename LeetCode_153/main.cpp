/**
    LeetCode_153
    https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int m = i + (j - i) / 2;
            if (nums[m] >= nums[j]) {
                i = m + 1;
            } else {
                j = m;
            }
        }
        return nums[i];
    }
};

int main() {
    return 0;
}
