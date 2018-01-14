/**
    LeetCode_628
    https://leetcode.com/problems/maximum-product-of-three-numbers/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        int ans1 = nums[0] * nums[1] * nums[n - 1];
        int ans2 = nums[n - 3] * nums[n - 2] * nums[n - 1];
        return max(ans1, ans2);
    }
};

int main() {
    return 0;
}
