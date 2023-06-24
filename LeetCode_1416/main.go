/**
  LeetCode_1416
  https://leetcode.com/problems/restore-the-array/
  MatrixDeity, 2023.
*/

package leetcode1416

const (
	mod int = 1e9 + 7
)

func numberOfArrays(s string, k int) int {
	n := len(s)
	dp := make([]int, n+1)
	for i := range dp {
		dp[i] = -1
	}

	var impl func(i int) int
	impl = func(i int) int {
		if i >= n {
			return 1
		}

		if s[i] == '0' {
			return 0
		}

		if dp[i] != -1 {
			return dp[i]
		}

		res, num := 0, 0
		for j := i; j < n; j++ {
			num = num*10 + int(s[j]-'0')
			if num > k {
				break
			}

			res = (res%mod + impl(j+1)%mod) % mod
		}

		dp[i] = res
		return res
	}

	return impl(0)
}
