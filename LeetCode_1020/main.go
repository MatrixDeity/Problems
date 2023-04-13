/**
  LeetCode_1020
  https://leetcode.com/problems/number-of-enclaves/
  MatrixDeity, 2023.
*/

package leetcode1020

func numEnclaves(grid [][]int) int {
	n, m := len(grid), len(grid[0])
	res := 0

	var impl func(i, j int, cnt *int) int
	impl = func(i, j int, cnt *int) int {
		if i < 0 || j < 0 || i >= n || j >= m {
			return 0
		}

		if grid[i][j] == 0 {
			return 1
		}

		grid[i][j] = 0
		*cnt++

		return impl(i-1, j, cnt) & impl(i+1, j, cnt) & impl(i, j-1, cnt) & impl(i, j+1, cnt)
	}

	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] == 1 {
				cnt := 0
				mult := impl(i, j, &cnt)
				res += cnt * mult
			}
		}
	}

	return res
}
