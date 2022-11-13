/**
  LeetCode_899
  https://leetcode.com/problems/orderly-queue/
  MatrixDeity, 2022.
*/

package leetcode899

import (
	"sort"
	"strings"
)

func orderlyQueue(s string, k int) string {
	if k > 1 {
		charArr := []byte(s)
		sort.Slice(charArr, func(i, j int) bool {
			return charArr[i] < charArr[j]
		})
		return string(charArr)
	}

	res := s
	builder := strings.Builder{}
	for i := range s {
		builder.Reset()
		builder.WriteString(s[i:])
		builder.WriteString(s[:i])
		curr := builder.String()
		if curr < res {
			res = curr
		}
	}
	return res
}
