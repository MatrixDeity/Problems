/**
  LeetCode_443
  https://leetcode.com/problems/string-compression/
  MatrixDeity, 2023.
*/

package leetcode443

import (
	"strconv"
)

func compress(chars []byte) int {
	outputIndex := 0
	currChar := chars[0]
	numChar := 0

	commit := func() {
		chars[outputIndex] = currChar
		outputIndex++

		if numChar > 1 {
			numCharStr := strconv.Itoa(numChar)
			for i := range numCharStr {
				chars[outputIndex] = numCharStr[i]
				outputIndex++
			}
		}
	}

	for i := range chars {
		if chars[i] == currChar {
			numChar++
			continue
		}

		commit()
		currChar = chars[i]
		numChar = 1
	}

	commit()

	return outputIndex
}
