/**
  LeetCode_64
  https://leetcode.com/problems/minimum-path-sum/
  MatrixDeity, 2023.
*/

package leetcode64

import "math"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minPathSum(grid [][]int) int {
	n, m := len(grid), len(grid[0])
	dp := make([][]int, n)

	for i := range dp {
		dp[i] = make([]int, m)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}
	dp[n-1][m-1] = grid[n-1][m-1]

	var impl func(i, j int) int
	impl = func(i, j int) int {
		if i >= n || j >= m {
			return math.MaxInt32
		}

		if dp[i][j] != -1 {
			return dp[i][j]
		}

		right := impl(i+1, j)
		down := impl(i, j+1)

		dp[i][j] = min(right, down) + grid[i][j]
		return dp[i][j]
	}

	return impl(0, 0)
}
