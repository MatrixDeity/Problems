/**
  LeetCode_374
  https://leetcode.com/problems/guess-number-higher-or-lower/
  MatrixDeity, 2022.
*/

package leetcode374

// just for code highlighting
func guess(n int) int {
	return 0
}

func guessNumber(n int) int {
	i, j := 1, n

	for i <= j {
		m := i + (j-i)/2
		g := guess(m)

		if g == 0 {
			return m
		}

		if g < 0 {
			j = m - 1
		} else {
			i = m + 1
		}
	}

	return 0
}
