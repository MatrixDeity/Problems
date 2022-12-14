/**
  LeetCode_2401
  https://leetcode.com/problems/longest-nice-subarray/
  MatrixDeity, 2022.
*/

package leetcode2401

func longestNiceSubarray(nums []int) int {
	n := len(nums)
	i, j := 0, 0
	binSum := 0
	currLen, res := 0, 0

	for j < n {
		if nums[j]&binSum == 0 {
			currLen++
			binSum &= nums[j]
			j++
		} else {
			currLen--
			binSum &= ^nums[i]
			i++
		}

		if currLen > res {
			res = currLen
		}
	}

	return res
}
