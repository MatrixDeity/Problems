/**
  LeetCode_879
  https://leetcode.com/problems/profitable-schemes/
  MatrixDeity, 2023.
*/

package leetcode879

import "fmt"

const (
	mod int = 1e9 + 7
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func profitableSchemes(n int, minProfit int, group []int, profit []int) int {
	dp := make(map[string]int)

	var impl func(i, membersNum, currProfit int) int
	impl = func(i, membersNum, currProfit int) int {
		if i == len(profit) {
			if currProfit >= minProfit {
				return 1
			}
			return 0
		}

		key := fmt.Sprintf("%d/%d/%d", i, membersNum, currProfit)
		if val, ok := dp[key]; ok {
			return val
		}

		ignore := impl(i+1, membersNum, currProfit)
		take := 0
		if membersNum+group[i] <= n {
			take = impl(i+1, membersNum+group[i], min(minProfit, currProfit+profit[i]))
		}

		dp[key] = (ignore + take) % mod
		return dp[key]
	}

	return impl(0, 0, 0)
}
