/**
  LeetCode_1833
  https://leetcode.com/problems/maximum-ice-cream-bars/description/
  MatrixDeity, 2023.
*/

package leetcode1833

import "sort"

func maxIceCream(costs []int, coins int) int {
	res := 0

	sort.Ints(costs)
	for _, cost := range costs {
		coins -= cost
		if coins >= 0 {
			res++
		} else {
			break
		}
	}

	return res
}
