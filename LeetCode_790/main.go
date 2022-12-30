/**
  LeetCode_790
  https://leetcode.com/problems/domino-and-tromino-tiling/
  MatrixDeity, 2022.
*/

package leetcode790

const (
	mod int = 1e9 + 7
)

func numTilings(n int) int {
	if n < 3 {
		return n
	}

	dp := make([]int, n+1)
	dp[0], dp[1], dp[2] = 1, 1, 2

	for i := 3; i <= n; i++ {
		dp[i] = (2*dp[i-1] + dp[i-3]) % mod
	}

	return dp[n]
}
