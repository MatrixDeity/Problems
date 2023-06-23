/**
  LeetCode_1027
  https://leetcode.com/problems/longest-arithmetic-subsequence/
  MatrixDeity, 2023.
*/

package leetcode1027

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func longestArithSeqLength(nums []int) int {
	res := 0
	n := len(nums)
	dp := make([]map[int]int, n)
	dp[0] = make(map[int]int)

	for i := 1; i < n; i++ {
		dp[i] = make(map[int]int)

		for j := 0; j < i; j++ {
			diff := nums[i] - nums[j]
			currCnt := 2

			if cnt, ok := dp[j][diff]; ok {
				currCnt = cnt + 1
			}

			dp[i][diff] = max(dp[i][diff], currCnt)
			res = max(currCnt, res)
		}
	}

	return res
}
