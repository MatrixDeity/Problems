/**
  LeetCode_1402
  https://leetcode.com/problems/reducing-dishes/
  MatrixDeity, 2023.
*/

package leetcode1402

import "sort"

func maxSatisfaction(satisfaction []int) int {
	res := 0

	sort.Slice(satisfaction, func(i, j int) bool {
		return satisfaction[i] > satisfaction[j]
	})

	fullSum := 0
	for _, s := range satisfaction {
		fullSum += s

		if fullSum+res <= res {
			break
		}

		res += fullSum
	}

	return res
}
