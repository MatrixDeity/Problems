/**
  LeetCode_2140
  https://leetcode.com/problems/solving-questions-with-brainpower/
  MatrixDeity, 2023.
*/

package leetcode2140

func max(a, b int64) int64 {
	if a < b {
		return b
	}
	return a
}

func mostPoints(questions [][]int) int64 {
	n := len(questions)
	dp := make([]int64, len(questions))
	for i := range dp {
		dp[i] = -1
	}

	var impl func(i int) int64
	impl = func(i int) int64 {
		if i >= n {
			return 0
		}

		if i == n-1 {
			return int64(questions[n-1][0])
		}

		if dp[i] != -1 {
			return dp[i]
		}

		takeItPoints := int64(questions[i][0]) + impl(i+questions[i][1]+1)
		notTakeItPoints := impl(i + 1)

		dp[i] = int64(max(takeItPoints, notTakeItPoints))

		return dp[i]
	}

	return impl(0)
}
