/**
  LeetCode_446
  https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
  MatrixDeity, 2022.
*/

package leetcode446

func numberOfArithmeticSlices(nums []int) int {
	n := len(nums)
	dp := make([]map[int]int, n)
	res := 0

	for i := range nums {
		if dp[i] == nil {
			dp[i] = make(map[int]int)
		}

		for j := i - 1; j >= 0; j-- {
			diff := nums[i] - nums[j]
			if val, ok := dp[j][diff]; ok {
				res += val
				dp[i][diff] += val
			}

			dp[i][diff]++
		}
	}

	return res
}
