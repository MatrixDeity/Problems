/**
    LeetCode_16
    https://leetcode.com/problems/3sum-closest/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int cur = nums[i] + nums[j] + nums[k];
                if (abs(target - cur) < abs(target - res))
                    res = cur;
                if (cur < target)
                    ++j;
                else
                    --k;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
