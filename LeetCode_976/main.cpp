/**
    LeetCode_976
    https://leetcode.com/problems/largest-perimeter-triangle/
    MatrixDeity, 2022.
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        for (size_t i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] < nums[i + 1] + nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }

        return 0;
    }
};
