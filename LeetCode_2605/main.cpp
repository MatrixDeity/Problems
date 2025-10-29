/**
    LeetCode_2605
    https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/
    MatrixDeity, 2023.
*/

#include <vector>

using namespace std;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        bool cntr1[10] = {};
        bool cntr2[10] = {};
        int min1 = 11;
        int min2 = 11;

        for (auto num : nums1) {
            min1 = min(min1, num);
            cntr1[num] = true;
        }

        for (auto num : nums2) {
            min2 = min(min2, num);
            cntr2[num] = true;
        }

        for (int i = 0; i < 10; ++i) {
            if (cntr1[i] && cntr2[i]) {
                return i;
            }
        }

        return min(min1 * 10 + min2, min2 * 10 + min1);
    }
};
