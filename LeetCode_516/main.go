/**
  LeetCode_516
  https://leetcode.com/problems/longest-palindromic-subsequence/
  MatrixDeity, 2023.
*/

package leetcode516

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func longestPalindromeSubseq(s string) int {
	n := len(s)
	dp := make([][]int, n)

	for i := range dp {
		dp[i] = make([]int, n)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}

	var impl func(i, j int) int
	impl = func(i, j int) int {
		if i == j {
			return 1
		}

		if i > j {
			return 0
		}

		if dp[i][j] != -1 {
			return dp[i][j]
		}

		if s[i] == s[j] {
			return impl(i+1, j-1) + 2
		}

		dp[i][j] = max(impl(i+1, j), impl(i, j-1))
		return dp[i][j]
	}

	return impl(0, n-1)
}
