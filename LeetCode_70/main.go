/**
  LeetCode_70
  https://leetcode.com/problems/climbing-stairs/
  MatrixDeity, 2022.
*/

package leetcode70

func climbStairs(n int) int {
	dp := make([]int, n+1)

	for i := range dp {
		if i < 3 {
			dp[i] = i
		} else {
			dp[i] = dp[i-1] + dp[i-2]
		}
	}

	return dp[n]
}
