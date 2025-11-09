/**
  LeetCode_1611
  hhttps://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
  MatrixDeity, 2025.
*/

package leetcode1611

func minimumOneBitOperations(n int) int {
	res := 0

	for n > 0 {
		res ^= n
		n /= 2
	}

	return res
}
