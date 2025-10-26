/**
  LeetCode_1547
  https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
  MatrixDeity, 2023.
*/

package leetcode1547

import "sort"

func minCost(size int, cuts []int) int {
	sort.Ints(cuts)
	cuts = append([]int{0}, cuts...)
	cuts = append(cuts, size)

	n := len(cuts) - 1
	big := size * (n + 1)

	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, n+1)
		for end := i; end <= n; end++ {
			dp[i][end] = big
		}

		dp[i][i+1] = 0
	}

	var impl func(i, j int) int
	impl = func(i, j int) int {
		if dp[i][j] < big {
			return dp[i][j]
		}

		diff := cuts[j] - cuts[i]
		for m := i + 1; m < j; m++ {
			cost := impl(i, m) + impl(m, j) + diff
			if dp[i][j] > cost {
				dp[i][j] = cost
			}
		}

		return dp[i][j]
	}

	return impl(0, n)
}
