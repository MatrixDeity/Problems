/**
  LeetCode_1262
  https://leetcode.com/problems/greatest-sum-divisible-by-three/
  MatrixDeity, 2025.
*/

package leetcode1262

import "math"

func maxSumDivThree(nums []int) int {
	dp := make([]int, 3)
	dp[0] = 0
	dp[1] = math.MinInt
	dp[2] = math.MinInt

	for _, num := range nums {
		tmp := make([]int, 3)
		copy(tmp, dp)
		for r := 0; r < 3; r++ {
			newR := (r + num%3) % 3
			tmp[newR] = max(tmp[newR], dp[r]+num)
		}
		copy(dp, tmp)
	}

	return dp[0]
}
