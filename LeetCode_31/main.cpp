/**
    LeetCode_31
    https://leetcode.com/problems/next-permutation/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = (int) nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            --i;
        if (i >= 0) {
            int j = n - 1;
            while (j >= 0 && nums[i] >= nums[j])
                --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    return 0;
}
