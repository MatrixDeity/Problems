/**
  LeetCode_451
  https://leetcode.com/problems/sort-characters-by-frequency/
  MatrixDeity, 2022.
*/

package leetcode451

import "sort"

func frequencySort(s string) string {
	counter := map[byte]int{}
	res := []byte(s)

	for _, char := range res {
		counter[char]++
	}

	sort.Slice(res, func(i, j int) bool {
		return counter[res[j]] < counter[res[i]] || (counter[res[i]] == counter[res[j]] && res[i] < res[j])
	})

	return string(res)
}
