/**
  LeetCode_1137
  https://leetcode.com/problems/n-th-tribonacci-number/
  MatrixDeity, 2023.
*/

package leetcode1137

func tribonacci(n int) int {
	if n == 0 {
		return 0
	}

	res := 1
	a, b := 0, 1

	for i := 3; i <= n; i++ {
		res, b, a = a+b+res, res, b
	}

	return res
}
