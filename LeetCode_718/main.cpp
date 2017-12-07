/**
    LeetCode_718
    https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = (int) A.size();
        int m = (int) B.size();
        int res = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
