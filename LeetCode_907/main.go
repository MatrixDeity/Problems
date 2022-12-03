/**
  LeetCode_907
  https://leetcode.com/problems/sum-of-subarray-minimums/
  MatrixDeity, 2022.
*/

package leetcode907

const (
	mod int = 1e9 + 7
)

func sumSubarrayMins(arr []int) int {
	stack := make([]int, 0, len(arr))
	dp := make([]int, len(arr))
	res := 0

	for i := range arr {
		for len(stack) > 0 && arr[stack[len(stack)-1]] >= arr[i] {
			stack = stack[:len(stack)-1]
		}

		if len(stack) > 0 {
			prev := stack[len(stack)-1]
			dp[i] = dp[prev] + (i-prev)*arr[i]
		} else {
			dp[i] = (i + 1) * arr[i]
		}

		res = (res + dp[i]) % mod
		stack = append(stack, i)
	}

	return res
}
