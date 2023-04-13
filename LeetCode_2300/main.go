/**
  LeetCode_2300
  https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
  MatrixDeity, 2023.
*/

package leetcode2300

import "sort"

func successfulPairs(spells []int, potions []int, success int64) []int {
	res := make([]int, len(spells))

	sort.Ints(potions)

	binsearch := func(spell int) int {
		i, j := 0, len(potions)-1

		for i <= j {
			m := i + (j-i)/2
			x := int64(potions[m]) * int64(spell)

			if x < success {
				i = m + 1
			} else {
				j = m - 1
			}
		}

		return len(potions) - i
	}

	for i, spell := range spells {
		res[i] = binsearch(spell)
	}

	return res
}
