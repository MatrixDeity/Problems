/**
  LeetCode_309
  https://leetcode.com/problems/word-pattern/
  MatrixDeity, 2023.
*/

package leetcode290

import "strings"

func wordPattern(pattern string, s string) bool {
	charsCounter := map[byte]int{}
	wordsCounter := map[string]int{}
	n := len(pattern)
	lastI := 0

	for i, word := range strings.Split(s, " ") {
		if i == n || charsCounter[pattern[i]] != wordsCounter[word] {
			return false
		}
		charsCounter[pattern[i]] = i + 1
		wordsCounter[word] = i + 1
		lastI = i + 1
	}

	return lastI == n
}
