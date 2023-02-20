/**
  LeetCode_1470
  https://leetcode.com/problems/shuffle-the-array/
  MatrixDeity, 2023.
*/

package leetcode1470

func shuffle(nums []int, n int) []int {
	res := make([]int, len(nums))
	j := 0

	for i := 0; i < n; i++ {
		res[j] = nums[i]
		j++
		res[j] = nums[i+n]
		j++
	}

	return res
}
