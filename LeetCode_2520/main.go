/**
  LeetCode_2520
  https://leetcode.com/problems/count-the-digits-that-divide-a-number/
  MatrixDeity, 2023.
*/

package leetcode2520

func countDigits(num int) int {
	n := num
	res := 0

	for n > 0 {
		dig := n % 10
		if num%dig == 0 {
			res++
		}
		n = n / 10
	}

	return res
}
