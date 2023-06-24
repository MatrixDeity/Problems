/**
  LeetCode_1318
  https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
  MatrixDeity, 2023.
*/

package leetcode1318

func minFlips(a int, b int, c int) int {
	res := 0

	for a|b|c != 0 {
		if (a|b)&1 != c&1 {
			res += a&1 + b&1 + c&1
		}

		a >>= 1
		b >>= 1
		c >>= 1
	}

	return res
}
