/**
  LeetCode_714
  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
  MatrixDeity, 2023.
*/

package leetcode714

func max(a int, b int) int {
	if a < b {
		return b
	}
	return a
}

func maxProfit(prices []int, fee int) int {
	n := len(prices)
	dp := make([][2]int, n)

	dp[0][1] = -prices[0]

	for i := 1; i < n; i++ {
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]-fee)
		dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i])
	}

	return max(dp[n-1][0], dp[n-1][1])
}
