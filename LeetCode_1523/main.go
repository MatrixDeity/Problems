/**
  LeetCode_1523
  https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
  MatrixDeity, 2023.
*/

package leetcode1523

func countOdds(low int, high int) int {
	res := (high-low)/2 + 1

	if low%2 == 0 && high%2 == 0 {
		res--
	}

	return res
}
