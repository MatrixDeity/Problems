/**
  LeetCode_2328
  https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/
  MatrixDeity, 2023.
*/

package leetcode2328

import "math"

const (
	mod int = 1e9 + 7
)

func countPaths(grid [][]int) int {
	n, m := len(grid), len(grid[0])

	dp := make([][]int, n)
	for i := range grid {
		dp[i] = make([]int, m)
	}

	var impl func(i, j, prev int) int
	impl = func(i, j, prev int) int {
		if i < 0 || i >= n || j < 0 || j >= m || prev <= grid[i][j] {
			return 0
		}

		if dp[i][j] > 0 {
			return dp[i][j]
		}

		dp[i][j] = 1

		dp[i][j] += impl(i-1, j, grid[i][j]) % mod
		dp[i][j] += impl(i+1, j, grid[i][j]) % mod
		dp[i][j] += impl(i, j-1, grid[i][j]) % mod
		dp[i][j] += impl(i, j+1, grid[i][j]) % mod

		return dp[i][j]
	}

	res := 0
	for i := range grid {
		for j := range grid[i] {
			res = (res + impl(i, j, math.MaxInt32)) % mod
		}
	}

	return res
}
