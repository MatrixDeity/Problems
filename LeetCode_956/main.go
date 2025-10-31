/**
  LeetCode_956
  https://leetcode.com/problems/tallest-billboard/
  MatrixDeity, 2023.
*/

package leetcode956

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func abs(x int) int {
	if x > 0 {
		return x
	}
	return -x
}

func tallestBillboard(rods []int) int {
	dp := map[int]int{0: 0}

	for _, rod := range rods {
		currDP := make(map[int]int)
		for key, val := range dp {
			currDP[key] = val
		}

		for diff, tall := range dp {
			currDP[diff+rod] = max(currDP[diff+rod], tall+rod)

			shor := tall - diff
			currDiff := abs(diff - rod)
			currDP[currDiff] = max(currDP[currDiff], max(tall, shor+rod))
		}

		dp = currDP
	}

	return dp[0]
}
