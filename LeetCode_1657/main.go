/**
  LeetCode_1657
  https://leetcode.com/problems/determine-if-two-strings-are-close/
  MatrixDeity, 2022.
*/

package leetcode1657

import "sort"

func closeStrings(word1 string, word2 string) bool {
	if len(word1) != len(word2) {
		return false
	}

	counter1, counter2 := make([]int, 26), make([]int, 26)

	for i := range word1 {
		counter1[word1[i]-'a']++
	}
	for i := range word2 {
		counter2[word2[i]-'a']++
	}

	for i := range counter1 {
		if counter1[i] != 0 && counter2[i] == 0 {
			return false
		}
		if counter2[i] != 0 && counter1[i] == 0 {
			return false
		}
	}

	sort.Ints(counter1)
	sort.Ints(counter2)

	for i := range counter1 {
		if counter1[i] != counter2[i] {
			return false
		}
	}

	return true
}
