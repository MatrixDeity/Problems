/**
  LeetCode_912
  https://leetcode.com/problems/sort-an-array/
  MatrixDeity, 2023.
*/

package leetcode912

func sortArray(nums []int) []int {
	i, j := 0, len(nums)-1
	pivot := nums[i+(i-i)/2]

	for i <= j {
		for nums[i] < pivot {
			i++
		}

		for pivot < nums[j] {
			j--
		}

		if i <= j {
			nums[i], nums[j] = nums[j], nums[i]
			i++
			j--
		}
	}

	if j > 0 {
		sortArray(nums[:j+1])
	}

	if i < len(nums) {
		sortArray(nums[i:])
	}

	return nums
}
