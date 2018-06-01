/**
    LeetCode_416
    https://leetcode.com/problems/partition-equal-subset-sum/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int fullSum = accumulate(nums.begin(), nums.end(), 0);
        if (fullSum % 2 == 1) {
            return false;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        function<bool(int, int)> impl = [&] (int idx, int partSum) {
            if (idx >= n || partSum - nums[idx] < 0) {
                return false;
            }
            if (partSum - nums[idx] == 0) {
                return true;
            }
            return impl(idx + 1, partSum - nums[idx]) || impl(idx + 1, partSum);
        };
        return impl(0, fullSum / 2);
    }
};

int main() {
    return 0;
}
