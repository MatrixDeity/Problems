/**
  LeetCode_2125
  https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
  MatrixDeity, 2025.
*/

package leetcode2125

import "strings"

func numberOfBeams(bank []string) int {
	res := 0
	prev := 0
	for _, line := range bank {
		curr := strings.Count(line, "1")
		if curr > 0 {
			res += prev * curr
			prev = curr
		}
	}

	return res
}
