/**
    LeetCode_565
    https://leetcode.com/problems/array-nesting/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<bool> used(n);
        for (int i = 0; i < n; ++i) {
            int cnt = 0, j = nums[i];
            while (!used[j]) {
                used[j] = true;
                j = nums[j];
                ++cnt;
            }
            res = max(cnt, res);
        }
        return res;
    }
};

int main() {
    return 0;
}
