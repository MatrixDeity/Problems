/**
  LeetCode_309
  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
  MatrixDeity, 2022.
*/

package leetcode309

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func maxProfit(prices []int) int {
	res1, res2 := 0, 0

	for i := 1; i < len(prices); i++ {
		tmp := res1
		res1 = max(res1+prices[i]-prices[i-1], res2)
		res2 = max(tmp, res2)
	}

	return max(res1, res2)
}
