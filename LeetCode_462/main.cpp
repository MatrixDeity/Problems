/**
    LeetCode_462
    https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, res = 0;
        sort(nums.begin(), nums.end());
        while (i < j) {
            res += nums[j] - nums[i];
            ++i, --j;
        }
        return res;
    }
};

int main() {
    return 0;
}
