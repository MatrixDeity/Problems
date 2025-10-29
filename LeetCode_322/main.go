/**
  LeetCode_322
  https://leetcode.com/problems/coin-change/
  MatrixDeity, 2023.
*/

package leetcode322

const (
	big int = 1e9
)

func coinChange(coins []int, amount int) int {
	dp := make(map[int]int)

	var impl func(rem int) int
	impl = func(rem int) int {
		if rem == 0 {
			return 0
		}

		if rem < 0 {
			return big
		}

		if res, ok := dp[rem]; ok {
			return res
		}

		res := big
		for _, coin := range coins {
			tmp := impl(rem-coin) + 1
			if tmp < res {
				res = tmp
			}
		}

		dp[rem] = res
		return res
	}

	res := impl(amount)
	if res != big {
		return res
	}
	return -1
}
