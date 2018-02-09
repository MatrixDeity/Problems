/**
    LeetCode_747
    https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int f = INT_MIN, s = INT_MIN, pos = -1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] > f) {
                s = f;
                f = nums[i];
                pos = i;
            } else if (nums[i] > s) {
                s = nums[i];
            }
        }
        return f >= 2 * s ? pos : -1;
    }
};

int main() {
    return 0;
}
