/**
    LeetCode_72
    https://leetcode.com/problems/edit-distance/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = (int) word1.size();
        int m = (int) word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if (word1[i - 1] != word2[j - 1])
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                else
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};

int main() {
    return 0;
}
