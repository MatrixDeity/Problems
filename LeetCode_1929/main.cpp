/**
    LeetCode_1929
    https://leetcode.com/problems/concatenation-of-array/
    MatrixDeity, 2022.
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        const int N = nums.size();
        vector<int> ans(2 * N);

        for (size_t i = 0; i < ans.size(); ++i) {
            ans[i] = nums[i % N];
        }

        return ans;
    }
};
