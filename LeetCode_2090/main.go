/**
  LeetCode_2090
  https://leetcode.com/problems/k-radius-subarray-averages/
  MatrixDeity, 2023.
*/

package leetcode2090

func getAverages(nums []int, k int) []int {
	n := len(nums)

	res := make([]int, n)
	for i := range nums {
		res[i] = -1
	}

	sum := 0
	frame := k + k + 1
	if frame > n {
		return res
	}

	for i := 0; i < frame; i++ {
		sum += nums[i]
	}

	res[k] = sum / frame
	for i := k + 1; i < n-k; i++ {
		sum += nums[i+k]
		sum -= nums[i-k-1]
		res[i] = sum / frame
	}

	return res
}
