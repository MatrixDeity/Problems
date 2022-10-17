/**
  LeetCode_1335
  https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
  MatrixDeity, 2022.
*/

package leetcode1335

import "math"

func minDifficulty(jobDifficulty []int, d int) int {
	n := len(jobDifficulty)

	if n < d {
		return -1
	}

	dp := make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = make([]int, d+1)
		for j := 0; j < d+1; j++ {
			dp[i][j] = -1
		}
	}

	maxInt := func(a, b int) int {
		if a > b {
			return a
		}
		return b
	}

	minInt := func(a, b int) int {
		if a < b {
			return a
		}
		return b
	}

	var impl func(int, int) int
	impl = func(idx, currD int) int {
		if currD == 1 {
			res := 0
			for i := idx; i < n; i++ {
				res = maxInt(res, jobDifficulty[i])
			}
			return res
		}

		if dp[idx][currD] != -1 {
			return dp[idx][currD]
		}

		max := 0
		res := math.MaxInt32

		for i := idx; i <= n-currD; i++ {
			max = maxInt(max, jobDifficulty[i])
			res = minInt(res, max+impl(i+1, currD-1))
		}

		dp[idx][currD] = res
		return dp[idx][currD]
	}

	return impl(0, d)
}
