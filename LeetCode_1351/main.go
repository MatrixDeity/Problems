/**
  LeetCode_1351
  https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
  MatrixDeity, 2023.
*/

package leetcode1351

func countNegatives(grid [][]int) int {
	n := len(grid[0])
	res := 0

	for _, row := range grid {
		i, j := 0, n-1

		for i <= j {
			m := i + (j-i)/2

			if row[m] < 0 {
				j = m - 1
			} else {
				i = m + 1
			}
		}

		res += n - i
	}

	return res
}
