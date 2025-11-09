/**
  LeetCode_2169
  https://leetcode.com/problems/count-operations-to-obtain-zero/
  MatrixDeity, 2025.
*/

package leetcode2169

func countOperations(num1 int, num2 int) int {
	if num1 == 0 || num2 == 0 {
		return 0
	}

	return num1/num2 + countOperations(num2, num1%num2)
}
