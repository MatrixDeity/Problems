/**
  LeetCode_1061
  https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
  MatrixDeity, 2023.
*/

package leetcode1061

import "strings"

const (
	n = 26
)

func smallestEquivalentString(s1 string, s2 string, baseStr string) string {
	dict := map[byte]byte{}

	for i := 0; i < n; i++ {
		dict[byte(i)+'a'] = byte(i) + 'a'
	}

	for i := range s1 {
		var actual, nonActual byte

		s1Val := dict[s1[i]]
		s2Val := dict[s2[i]]
		if s1Val < s2Val {
			actual = s1Val
			nonActual = s2Val
		} else {
			actual = s2Val
			nonActual = s1Val
		}

		for j := 0; j < n; j++ {
			if dict[byte(j)+'a'] == nonActual {
				dict[byte(j)+'a'] = actual
			}
		}
	}

	builder := strings.Builder{}
	for i := range baseStr {
		builder.WriteByte(dict[baseStr[i]])
	}

	return builder.String()
}
