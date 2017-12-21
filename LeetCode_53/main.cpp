/**
    LeetCode_53
    https://leetcode.com/problems/maximum-subarray/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int n = (int) nums.size();
        int res = nums[0];
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            res = max(res, sum);
            sum = max(sum, 0);
        }
        return res;
    }
};

int main() {
    return 0;
}
