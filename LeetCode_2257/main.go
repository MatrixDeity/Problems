/**
  LeetCode_2257
  https://leetcode.com/problems/count-unguarded-cells-in-the-grid/
  MatrixDeity, 2025.
*/

package leetcode2257

func countUnguarded(m int, n int, guards [][]int, walls [][]int) int {
	grid := make([][]int, m)
	for i := range grid {
		grid[i] = make([]int, n)
	}

	for _, wall := range walls {
		grid[wall[0]][wall[1]] = 2
	}

	for _, guard := range guards {
		grid[guard[0]][guard[1]] = 2
		line(grid, 1, guard[0], guard[1], -1, 0, m, n)
		line(grid, 1, guard[0], guard[1], 1, 0, m, n)
		line(grid, -1, guard[0], guard[1], 0, -1, m, n)
		line(grid, -1, guard[0], guard[1], 0, 1, m, n)
	}

	res := n * m
	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] != 0 {
				res--
			}
		}
	}

	return res
}

func line(grid [][]int, dir, si, sj, di, dj, m, n int) {
	i, j := si+di, sj+dj

	for i < m && j < n && i >= 0 && j >= 0 {
		if grid[i][j] == 2 || grid[i][j] == dir {
			break
		}

		if grid[i][j] == 0 {
			grid[i][j] = dir
		}

		i += di
		j += dj
	}
}
