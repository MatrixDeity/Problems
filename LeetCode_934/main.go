/**
  LeetCode_934
  https://leetcode.com/problems/shortest-bridge/
  MatrixDeity, 2023.
*/

package leetcode934

type Edge struct {
	from int
	to   int
}

func shortestBridge(grid [][]int) int {
	queue := []Edge{}
	m, n := len(grid), len(grid[0])
	from, to := -1, -1

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				from = i
				to = j
				break
			}
		}
	}

	var impl func(i, j int)
	impl = func(i, j int) {
		if i < 0 || j < 0 || i >= len(grid) || j >= len(grid[0]) || grid[i][j] != 1 {
			return
		}

		grid[i][j] = -1

		queue = append(queue, Edge{i, j})
		impl(i+1, j)
		impl(i-1, j)
		impl(i, j+1)
		impl(i, j-1)
	}

	impl(from, to)

	res := 0
	dirs := [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}

	for len(queue) > 0 {
		size := len(queue)

		for i := 0; i < size; i++ {
			curr := queue[0]
			queue = queue[1:]

			for _, dir := range dirs {
				nextFrom := curr.from + dir[0]
				nextTo := curr.to + dir[1]

				if nextFrom < 0 || nextTo < 0 || nextFrom >= m || nextTo >= n || grid[nextFrom][nextTo] == -1 {
					continue
				}

				if grid[nextFrom][nextTo] == 1 {
					return res
				}

				queue = append(queue, Edge{nextFrom, nextTo})
				grid[nextFrom][nextTo] = -1
			}
		}

		res++
	}

	return res
}
