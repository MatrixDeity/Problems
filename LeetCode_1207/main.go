/**
  LeetCode_1207
  https://leetcode.com/problems/unique-number-of-occurrences/
  MatrixDeity, 2022.
*/

package leetcode1207

func uniqueOccurrences(arr []int) bool {
	counter := map[int]int{}
	for _, num := range arr {
		counter[num]++
	}

	set := map[int]struct{}{}
	for _, cnt := range counter {
		if _, ok := set[cnt]; ok {
			return false
		}

		set[cnt] = struct{}{}
	}

	return true
}
