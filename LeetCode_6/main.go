/**
  LeetCode_6
  https://leetcode.com/problems/zigzag-conversion/
  MatrixDeity, 2023.
*/

package leetcode6

import (
	"strings"
)

func convert(s string, numRows int) string {
	builders := make([]strings.Builder, numRows+1)

	for i := 0; i < len(s); {
		for j := 0; j < numRows && i < len(s); j++ {
			builders[j].WriteByte(s[i])
			i++
		}

		for j := numRows - 2; 0 < j && i < len(s); j-- {
			builders[j].WriteByte(s[i])
			i++
		}
	}

	res := strings.Builder{}
	for _, r := range builders {
		res.WriteString(r.String())
	}

	return res.String()
}
