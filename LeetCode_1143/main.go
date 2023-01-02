/**
  LeetCode_1143
  https://leetcode.com/problems/longest-common-subsequence/
  MatrixDeity, 2022.
*/

package leetcode1143

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func longestCommonSubsequence(text1 string, text2 string) int {
	var n, m int = len(text1), len(text2)
	dp := make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = make([]int, m+1)
	}

	for i := 1; i < n+1; i++ {
		for j := 1; j < m+1; j++ {
			if text1[i-1] == text2[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = max(dp[i][j-1], dp[i-1][j])
			}
		}
	}

	return dp[n][m]
}
