/**
  LeetCode_837
  https://leetcode.com/problems/new-21-game/
  MatrixDeity, 2023.
*/

package leetcode837

func new21Game(n int, k int, maxPts int) float64 {
	dp := make([]float64, n+1)
	dp[0] = 1.0

	sum := 0.0
	if k > 0 {
		sum = 1.0
	}

	res := 0.0
	for i := 1; i <= n; i++ {
		dp[i] += sum / float64(maxPts)

		if i < k {
			sum += dp[i]
		}

		if i >= maxPts && i < k+maxPts {
			sum -= dp[i-maxPts]
		}
	}

	for i := k; i <= n; i++ {
		res += dp[i]
	}

	return res
}
