/**
  LeetCode_2279
  https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
  MatrixDeity, 2022.
*/

package leetcode2279

import "sort"

func maximumBags(capacity []int, rocks []int, additionalRocks int) int {
	for i := range capacity {
		capacity[i] = capacity[i] - rocks[i]
	}

	sort.Ints(capacity)

	res := 0
	for _, cap := range capacity {
		if cap > additionalRocks {
			break
		}

		res++
		additionalRocks -= cap
	}

	return res
}
