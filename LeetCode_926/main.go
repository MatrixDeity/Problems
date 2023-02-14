/**
  LeetCode_926
  https://leetcode.com/problems/flip-string-to-monotone-increasing/
  MatrixDeity, 2023.
*/

package leetcode926

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minFlipsMonoIncr(s string) int {
	ones, zeros := 0, 0

	for i := range s {
		if s[i] == '1' {
			ones++
		} else {
			zeros = min(zeros+1, ones)
		}
	}

	return zeros
}
