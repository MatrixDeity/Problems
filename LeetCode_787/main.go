/**
  LeetCode_787
  https://leetcode.com/problems/cheapest-flights-within-k-stops/
  MatrixDeity, 2023.
*/

package leetcode787

import "math"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func findCheapestPrice(n int, flights [][]int, src int, dst int, k int) int {
	dp := make([]int, n)
	for i := 0; i < n; i++ {
		dp[i] = math.MaxInt32
	}
	dp[src] = 0

	for i := 0; i <= k; i++ {
		tmp := make([]int, len(dp))
		copy(tmp, dp)

		for _, flight := range flights {
			from, to, cost := flight[0], flight[1], flight[2]

			if dp[from] < math.MaxInt32 {
				tmp[to] = min(tmp[to], dp[from]+cost)
			}
		}

		dp = tmp
	}

	if dp[dst] == math.MaxInt32 {
		return -1
	}

	return dp[dst]
}
