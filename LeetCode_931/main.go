/**
  LeetCode_931
  https://leetcode.com/problems/minimum-falling-path-sum/
  MatrixDeity, 2022.
*/

package leetcode931

import "math"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minFallingPathSum(matrix [][]int) int {
	n, m := len(matrix), len(matrix[0])
	res := math.MaxInt32
	dp := make([]map[int]int, n)
	for i := range dp {
		dp[i] = map[int]int{}
	}

	var impl func(i, j int) int
	impl = func(i, j int) int {
		if i < 0 || j < 0 || i >= n || j >= m {
			return math.MaxInt32
		}

		if i == n-1 {
			return matrix[i][j]
		}

		if val, ok := dp[i][j]; ok {
			return val
		}

		down := impl(i+1, j)
		downLeft := impl(i+1, j-1)
		downRight := impl(i+1, j+1)

		curr := min(down, min(downLeft, downRight)) + matrix[i][j]
		dp[i][j] = curr
		return curr
	}

	for j := 0; j < m; j++ {
		res = min(impl(0, j), res)
	}

	return res
}
