/**
    LeetCode_334
    https://leetcode.com/problems/increasing-triplet-subsequence/
    MatrixDeity, 2022.
*/

#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int l = INT32_MAX, m = INT32_MAX;

        for (int num : nums) {
            if (l < m && m < num) {
                return true;
            }
            if (num < m && l < num) {
                m = num;
            } else if (num < l) {
                l = num;
            }
        }

        return false;
    }
};
