/**
    LeetCode_566
    https://leetcode.com/problems/reshape-the-matrix/description/
    MatrixDeity, 2018.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size() * nums.front().size() != r * c)
            return nums;

        vector<vector<int>> res(r, vector<int>(c));
        int n = (int) nums.size(), m = (int) nums.front().size(), all = n * m;
        for (int i = 0; i < all; ++i) {
            res[i / c][i % c] = nums[i / m][i % m];
        }
        return res;
    }
};

int main() {
    return 0;
}
