/**
  LeetCode_980
  https://leetcode.com/problems/unique-paths-iii/
  MatrixDeity, 2022.
*/

package leetcode980

func uniquePathsIII(grid [][]int) int {
	n, m := len(grid), len(grid[0])

	var impl func(i int, j int, rem int) int
	impl = func(i, j, rem int) int {
		if i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1 {
			return 0
		}

		if grid[i][j] == 2 {
			if rem < 0 {
				return 1
			}
			return 0
		}

		rem--
		grid[i][j] = -1
		up := impl(i-1, j, rem)
		down := impl(i+1, j, rem)
		left := impl(i, j-1, rem)
		right := impl(i, j+1, rem)
		grid[i][j] = 0

		return up + down + left + right
	}

	count := 0
	startI, startJ := 0, 0

	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] == 1 {
				startI, startJ = i, j
			} else if grid[i][j] == 0 {
				count++
			}
		}
	}

	return impl(startI, startJ, count)
}
