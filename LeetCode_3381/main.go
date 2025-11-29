/**
  LeetCode_3381
  https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/
  MatrixDeity, 2025.
*/

package leetcode3381

import "math"

func maxSubarraySum(nums []int, k int) int64 {
	const mx = math.MaxInt / 2
	sums := make([]int, k)
	for i := range sums {
		sums[i] = mx
	}
	prefix := 0
	res := -mx
	sums[k-1] = 0

	for i := range nums {
		prefix += nums[i]
		res = max(res, prefix-sums[i%k])
		sums[i%k] = min(sums[i%k], prefix)
	}

	return int64(res)
}
