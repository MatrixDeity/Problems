/**
    LeetCode_154
    https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        for (int i = 1; i < n; ++i) {
            res = min(nums[i], res);
        }
        return res;
    }
};

int main() {
    return 0;
}
