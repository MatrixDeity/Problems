/**
  LeetCode_474
  https://leetcode.com/problems/ones-and-zeroes/
  MatrixDeity, 2025.
*/

package leetcode474

import "strings"

func findMaxForm(strs []string, m int, n int) int {
	const N = 101

	dp := make([][]int, N)
	for i := range dp {
		dp[i] = make([]int, N)
	}

	for _, str := range strs {
		cnt0 := strings.Count(str, "0")
		cnt1 := len(str) - cnt0

		for i := m; i >= cnt0; i-- {
			for j := n; j >= cnt1; j-- {
				dp[i][j] = max(dp[i][j], 1+dp[i-cnt0][j-cnt1])
			}
		}
	}

	return dp[m][n]
}
