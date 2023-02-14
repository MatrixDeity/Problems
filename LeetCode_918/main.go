/**
  LeetCode_918
  https://leetcode.com/problems/maximum-sum-circular-subarray/
  MatrixDeity, 2023.
*/

package leetcode918

import "math"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func maxSubarraySumCircular(nums []int) int {
	maxSum, minSum := math.MinInt32, math.MaxInt32
	currMax, currMin := 0, 0
	fullSum := 0

	for _, num := range nums {
		fullSum += num

		currMin = min(currMin+num, num)
		currMax = max(currMax+num, num)

		minSum = min(currMin, minSum)
		maxSum = max(currMax, maxSum)
	}

	if maxSum < 0 {
		return maxSum
	}
	return max(fullSum-minSum, maxSum)
}
