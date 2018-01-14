/**
    LeetCode_283
    https://leetcode.com/problems/move-zeroes/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int res = 0;
        int n = (int) nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                nums[res] = nums[i];
                ++res;
            }
        }
        for (; res < n; ++res)
            nums[res] = 0;
    }
};

int main() {
    return 0;
}
