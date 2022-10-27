/**
  LeetCode_343
  https://leetcode.com/problems/integer-break/
  MatrixDeity, 2022.
*/

package leetcode343

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func integerBreak(n int) int {
	dp := make([]int, n+1)
	for i := range dp {
		dp[i] = -1
	}

	var impl func(int) int
	impl = func(n int) int {
		if n < 3 {
			return 1
		}

		if dp[n] != -1 {
			return dp[n]
		}

		res := 1
		for i := 1; i < n; i++ {
			rem := n - i
			res = max(res, i*max(rem, impl(rem)))
		}

		dp[n] = res
		return res
	}

	return impl(n)
}
