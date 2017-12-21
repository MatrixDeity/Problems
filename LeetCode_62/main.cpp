/**
    LeetCode_62
    https://leetcode.com/problems/unique-paths/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;

        vector<vector<int>> dp(n, vector<int>(m, 1));
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp.back().back();
    }
};

int main() {
    return 0;
}
