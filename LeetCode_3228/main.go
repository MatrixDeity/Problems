/**
  LeetCode_3228
  https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/
  MatrixDeity, 2025.
*/

package leetcode3228

func maxOperations(s string) int {
	ones := 0
	res := 0
	for i := range s {
		if s[i] == '1' {
			ones++
		} else if i > 0 && s[i-1] == '1' {
			res += ones
		}
	}

	return res
}
