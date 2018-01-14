/**
    LeetCode_674
    https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = (int) nums.size();
        int ans = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                ++cnt;
                ans = max(cnt, ans);
            } else {
                cnt = 1;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
