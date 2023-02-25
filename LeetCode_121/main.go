/**
  LeetCode_121
  https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
  MatrixDeity, 2023.
*/

package leetcode121

func maxProfit(prices []int) int {
	res := 0
	minPrice := prices[0]

	for _, price := range prices {
		diff := price - minPrice
		if diff > res {
			res = diff
		}

		if price < minPrice {
			minPrice = price
		}
	}

	return res
}
