/**
  LeetCode_35
  https://leetcode.com/problems/search-insert-position/
  MatrixDeity, 2023.
*/

package leetcode35

func searchInsert(nums []int, target int) int {
	i, j := 0, len(nums)-1

	for i <= j {
		m := i + (j-i)/2
		if nums[m] < target {
			i = m + 1
		} else {
			j = m - 1
		}
	}

	return i
}
