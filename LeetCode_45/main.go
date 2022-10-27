/**
  LeetCode_45
  https://leetcode.com/problems/jump-game-ii/
  MatrixDeity, 2022.
*/

package leetcode45

import "math"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func jump(nums []int) int {
	end := len(nums) - 1
	dp := make([]int, end+1)
	for i := range dp {
		dp[i] = -1
	}

	var impl func(int) int
	impl = func(i int) int {
		if i == end {
			return 0
		}
		if dp[i] != -1 {
			return dp[i]
		}

		res := math.MaxInt32
		num := nums[i]
		for j := i + 1; j <= min(i+num, end); j++ {
			res = min(res, impl(j)+1)
		}

		dp[i] = res
		return res
	}

	return impl(0)
}
