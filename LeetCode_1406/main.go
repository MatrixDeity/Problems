/**
  LeetCode_1406
  https://leetcode.com/problems/stone-game-iii/
  MatrixDeity, 2023.
*/

package leetcode1406

import "math"

func stoneGameIII(stoneValue []int) string {
	dp := make([]int, len(stoneValue))
	for i := range dp {
		dp[i] = math.MinInt
	}

	var impl func(i int) int
	impl = func(i int) int {
		if i == len(stoneValue) {
			return 0
		}

		if dp[i] != math.MinInt {
			return dp[i]
		}

		sum := 0
		for j := 0; j <= 2 && i+j < len(stoneValue); j++ {
			sum += stoneValue[i+j]

			res := sum - impl(i+j+1)
			if res > dp[i] {
				dp[i] = res
			}
		}

		return dp[i]
	}

	res := impl(0)
	if res > 0 {
		return "Alice"
	}
	if res < 0 {
		return "Bob"
	}
	return "Tie"
}
