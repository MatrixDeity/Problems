/**
  LeetCode_2544
  https://leetcode.com/problems/alternating-digit-sum/
  MatrixDeity, 2023.
*/

package leetcode2544

func alternateDigitSum(n int) int {
	res := 0
	sign := 1

	for n > 0 {
		d := n % 10
		res += d * sign
		sign *= -1
		n /= 10
	}

	if sign > 0 {
		return -res
	}
	return res
}
