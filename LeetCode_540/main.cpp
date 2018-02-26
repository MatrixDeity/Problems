/**
    LeetCode_540
    https://leetcode.com/problems/single-element-in-a-sorted-array/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int m = i + (j - i) / 2;
            if (nums[m] == nums[m ^ 1])
                i = m + 1;
            else
                j = m - 1;
        }
        return nums[i];
    }
};

int main() {
    return 0;
}
