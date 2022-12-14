/**
  LeetCode_198
  https://leetcode.com/problems/house-robber/
  MatrixDeity, 2022.
*/

package leetcode198

import "math"

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func rob(nums []int) int {
	n := len(nums)
	dp := map[int]int{}

	var impl func(i int) int
	impl = func(i int) int {
		if i > n {
			return math.MinInt32
		}

		if i == n {
			return 0
		}

		if val, ok := dp[i]; ok {
			return val
		}

		res := nums[i]
		res = max(res, nums[i]+impl(i+2))
		res = max(res, nums[i]+impl(i+3))
		dp[i] = res
		return res
	}

	return max(impl(0), impl(1))
}
