/**
  LeetCode_151
  https://leetcode.com/problems/reverse-words-in-a-string/
  MatrixDeity, 2022.
*/

package leetcode151

import "strings"

func splitWords(str string) []string {
	builder := strings.Builder{}
	res := []string{}

	for _, r := range str {
		if r == ' ' {
			if builder.Len() > 0 {
				res = append(res, builder.String())
				builder.Reset()
			}
		} else {
			builder.WriteRune(r)
		}
	}

	if builder.Len() > 0 {
		res = append(res, builder.String())
	}

	return res
}

func reverseWords(s string) string {
	builder := strings.Builder{}
	words := splitWords(s)
	n := len(words)

	builder.WriteString(words[n-1])
	for i := n - 2; i >= 0; i-- {
		builder.WriteByte(' ')
		builder.WriteString(words[i])
	}

	return builder.String()
}
