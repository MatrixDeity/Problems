/**
  LeetCode_1662
  https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
  MatrixDeity, 2022.
*/

package leetcode1662

import "strings"

func join(words []string) string {
	builder := strings.Builder{}
	for _, word := range words {
		builder.WriteString(word)
	}
	return builder.String()
}

func arrayStringsAreEqual(word1 []string, word2 []string) bool {
	return join(word1) == join(word2)
}
