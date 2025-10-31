/**
  LeetCode_2124
  https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
  MatrixDeity, 2025.
*/

package leetcode884

import "strings"

func uncommonFromSentences(s1 string, s2 string) []string {
	words1 := strings.Split(s1, " ")
	words2 := strings.Split(s2, " ")
	n := len(words1) + len(words2)

	counter := make(map[string]int, n)
	for _, w := range words1 {
		counter[w]++
	}
	for _, w := range words2 {
		counter[w]++
	}

	res := make([]string, 0, n)
	for w, cnt := range counter {
		if cnt == 1 {
			res = append(res, w)
		}
	}

	return res
}
