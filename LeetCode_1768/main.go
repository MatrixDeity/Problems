/**
  LeetCode_1768
  https://leetcode.com/problems/merge-strings-alternately/
  MatrixDeity, 2023.
*/

package leetcode1768

import (
	"strings"
)

func mergeAlternately(word1 string, word2 string) string {
	builder := strings.Builder{}
	builder.Grow(len(word1) + len(word2))

	i := 0
	for ; i < len(word1) && i < len(word2); i++ {
		builder.WriteByte(word1[i])
		builder.WriteByte(word2[i])
	}

	for ; i < len(word1); i++ {
		builder.WriteByte(word1[i])
	}

	for ; i < len(word2); i++ {
		builder.WriteByte(word2[i])
	}

	return builder.String()
}
