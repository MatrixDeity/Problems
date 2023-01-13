/**
  LeetCode_2161
  https://leetcode.com/problems/maximum-ice-cream-bars/
  MatrixDeity, 2023.
*/

package leetcode2161

func pivotArray(nums []int, pivot int) []int {
	res := make([]int, 0, len(nums))

	for _, num := range nums {
		if num < pivot {
			res = append(res, num)
		}
	}

	for _, num := range nums {
		if num == pivot {
			res = append(res, num)
		}
	}

	for _, num := range nums {
		if num > pivot {
			res = append(res, num)
		}
	}

	return res
}
