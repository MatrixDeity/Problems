/**
  LeetCode_1480
  https://leetcode.com/problems/running-sum-of-1d-array/
  MatrixDeity, 2022.
*/

package leetcode1480

func runningSum(nums []int) []int {
	res := make([]int, len(nums))
	sum := 0

	for i, v := range nums {
		sum += v
		res[i] = sum
	}

	return res
}
