/**
  LeetCode_1802
  https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
  MatrixDeity, 2023.
*/

package leetcode1802

import "sort"

func maxValue(n int, index int, maxSum int) int {
	return sort.Search(maxSum, func(num int) bool {
		res := num * num

		if tmp := num - index; tmp > 1 {
			res -= (tmp - 1) * tmp / 2
		}

		if tmp := num - (n - 1 - index); tmp > 1 {
			res -= (tmp - 1) * tmp / 2
		}

		return res > maxSum-n
	})
}
