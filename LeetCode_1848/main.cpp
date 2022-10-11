/**
    LeetCode_1848
    https://leetcode.com/problems/minimum-distance-to-the-target-element/
    MatrixDeity, 2022.
*/

#include <vector>

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = INT32_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                res = min(abs(i - start), res);
            }
        }

        return res;
    }
};
