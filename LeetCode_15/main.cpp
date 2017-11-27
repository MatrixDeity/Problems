/**
    LeetCode_15
    https://leetcode.com/problems/3sum/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = n - 1;
            int tar = -nums[i];
            while (j < k) {
                if (nums[j] + nums[k] == tar) {
                    res.push_back({ nums[i], nums[j], nums[k] });
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j - 1])
                        ++j;
                    while (j < k && nums[k] == nums[k + 1])
                        --k;
                } else if (nums[j] + nums[k] < tar) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
