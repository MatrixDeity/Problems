/**
    LeetCode_152
    https://leetcode.com/problems/maximum-product-subarray/discuss/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using ll = long long;

    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int n = (int) nums.size();
        ll up = nums[0], down = nums[0], res = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] < 0)
                swap(up, down);
            up = max(up * nums[i], (ll) nums[i]);
            down = min(down * nums[i], (ll) nums[i]);
            res = max(up, res);
        }
        return res;
    }
};

int main() {
    return 0;
}
