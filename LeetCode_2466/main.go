/**
  LeetCode_2466
  https://leetcode.com/problems/count-ways-to-build-good-strings/
  MatrixDeity, 2023.
*/

package leetcode2466

const (
	mod int = 1e9 + 7
)

func countGoodStrings(low int, high int, zero int, one int) int {
	dp := make([]int, high+1)
	for i := range dp {
		dp[i] = -1
	}

	var impl func(i int) int
	impl = func(i int) int {
		if i > high {
			return 0
		}

		if dp[i] == -1 {
			isOK := 0
			if low <= i && i <= high {
				isOK = 1
			}

			zeros := impl(i+zero) % mod
			ones := impl(i+one) % mod

			dp[i] = (isOK + zeros + ones) % mod
		}

		return dp[i]
	}

	return impl(0)
}
