/**
    LeetCode_665
    https://leetcode.com/problems/non-decreasing-array/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                if (i < 2 || nums[i - 2] <= nums[i])
                    nums[i - 1] = nums[i - 2];
                else
                    nums[i] = nums[i - 1];
                if (cnt++ > 0)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
