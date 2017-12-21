/**
    LeetCode_64
    https://leetcode.com/problems/minimum-path-sum/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using ll = long long;

    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;

        int n = (int) grid.size();
        int m = (int) grid.front().size();
        vector<vector<ll>> dp(n, vector<ll>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j != 0)
                    dp[0][j] = dp[0][j - 1] + grid[0][j];
                else if (i != 0 && j == 0)
                    dp[i][0] = dp[i - 1][0] + grid[i][0];
                else if (i != 0 && j != 0)
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                else
                    dp[0][0] = grid[0][0];
            }
        }
        return dp.back().back();
    }
};

int main() {
    return 0;
}
