/**
  LeetCode_2485
  https://leetcode.com/problems/find-the-pivot-integer/
  MatrixDeity, 2022.
*/

package leetcode2485

func pivotInteger(n int) int {
	leftSum := 0
	rightSum := n * (n + 1) / 2

	for i := 1; i <= n; i++ {
		leftSum += i
		if leftSum == rightSum {
			return i
		}
		rightSum -= i
	}

	return -1
}
