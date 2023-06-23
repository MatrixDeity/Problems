/**
  LeetCode_1312
  https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
  MatrixDeity, 2023.
*/

package leetcode1312

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minInsertions(s string) int {
	n := len(s)
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)
		for j := 0; j < n; j++ {
			dp[i][j] = -1
		}
	}

	var impl func(int, int) int
	impl = func(i, j int) int {
		if j-i <= 0 {
			return 0
		}

		if dp[i][j] != -1 {
			return dp[i][j]
		}

		if s[i] == s[j] {
			dp[i+1][j-1] = impl(i+1, j-1)
			dp[i][j] = dp[i+1][j-1]

			return dp[i][j]
		}

		dp[i][j] = 1 + min(impl(i+1, j), impl(i, j-1))

		return dp[i][j]
	}

	return impl(0, n-1)
}
