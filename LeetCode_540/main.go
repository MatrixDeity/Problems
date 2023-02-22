/**
  LeetCode_540
  https://leetcode.com/problems/single-element-in-a-sorted-array/
  MatrixDeity, 2023.
*/

package leetcode540

func singleNonDuplicate(nums []int) int {
	i, j := 0, len(nums)-1

	for i < j {
		m := i + (j-i)/2
		if nums[m] == nums[m^1] {
			i = m + 1
		} else {
			j = m
		}
	}

	return nums[i]
}
