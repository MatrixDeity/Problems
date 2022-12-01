/**
  LeetCode_279
  https://leetcode.com/problems/perfect-squares/
  MatrixDeity, 2022.
*/

package leetcode279

const (
	bigInt int = 1e9
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func numSquares(n int) int {
	dp := make([]int, n+1)
	for i := range dp {
		dp[i] = -1
	}

	var impl func(n int) int
	impl = func(n int) int {
		if n == 0 {
			return 0
		}

		if dp[n] != -1 {
			return dp[n]
		}

		res := bigInt
		for i := 1; i*i <= n; i++ {
			res = min(impl(n-i*i)+1, res)
		}
		dp[n] = res
		return res
	}

	return impl(n)
}
