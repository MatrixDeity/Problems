/**
  LeetCode_1572
  https://leetcode.com/problems/matrix-diagonal-sum/
  MatrixDeity, 2023.
*/

package leetcode1572

func diagonalSum(mat [][]int) int {
	n := len(mat)
	res := 0

	for i := 0; i < n; i++ {
		res += mat[i][i] + mat[i][n-i-1]
	}

	if n&1 == 1 {
		res -= mat[n/2][n/2]
	}

	return res
}
