/**
  LeetCode_258
  https://leetcode.com/problems/add-digits/
  MatrixDeity, 2023.
*/

package leetcode258

func addDigits(num int) int {
	if num == 0 {
		return 0
	}

	if num%9 == 0 {
		return 9
	}

	return num % 9
}
