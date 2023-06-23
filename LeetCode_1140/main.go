/**
  LeetCode_1140
  https://leetcode.com/problems/stone-game-ii/
  MatrixDeity, 2023.
*/

package leetcode1140

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func stoneGameII(piles []int) int {
	n := len(piles)
	sums := make([]int, n+1)
	for i := n - 1; i >= 0; i-- {
		sums[i] = sums[i+1] + piles[i]
	}

	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
		for j := range dp[i] {
			dp[i][j] = 0
		}
	}

	var impl func(i, j int) int
	impl = func(i, j int) int {
		if i >= n {
			return 0
		}

		res := dp[i][j]
		if res > 0 {
			return res
		}

		for k := 1; k <= 2*j; k++ {
			res = max(sums[i]-impl(i+k, max(j, k)), res)
		}

		dp[i][j] = res
		return res
	}

	return impl(0, 1)
}
