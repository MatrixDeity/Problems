/**
  LeetCode_881
  https://leetcode.com/problems/boats-to-save-people/
  MatrixDeity, 2023.
*/

package leetcode881

import "sort"

func numRescueBoats(people []int, limit int) int {
	i, j := 0, len(people)-1
	res := 0

	sort.Ints(people)

	for i <= j {
		curr := people[i] + people[j]

		if curr <= limit {
			i++
			j--
		} else {
			j--
		}

		res++
	}

	return res
}
