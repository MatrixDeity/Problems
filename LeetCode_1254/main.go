/**
  LeetCode_1254
  https://leetcode.com/problems/number-of-closed-islands/
  MatrixDeity, 2023.
*/

package leetcode1254

func closedIsland(grid [][]int) int {
	n, m := len(grid), len(grid[0])
	res := 0

	var impl func(i, j int) int
	impl = func(i, j int) int {
		if i < 0 || j < 0 || i >= n || j >= m {
			return 0
		}

		if grid[i][j] == 1 {
			return 1
		}

		grid[i][j] = 1

		return impl(i-1, j) & impl(i+1, j) & impl(i, j-1) & impl(i, j+1)
	}

	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] == 0 {
				res += impl(i, j)
			}
		}
	}

	return res
}
