/**
  LeetCode_704
  https://leetcode.com/problems/binary-search/
  MatrixDeity, 2023.
*/

package leetcode704

func search(nums []int, target int) int {
	i, j := 0, len(nums)-1

	for i <= j {
		m := i + (j-i)/2
		x := nums[m]

		if x == target {
			return m
		}

		if x < target {
			i = m + 1
		} else {
			j = m - 1
		}
	}

	return -1
}
