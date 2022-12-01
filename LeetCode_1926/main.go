/**
  LeetCode_1926
  https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
  MatrixDeity, 2022.
*/

package leetcode1926

type point struct {
	x, y int
}

func nearestExit(maze [][]byte, entrance []int) int {
	queue := []point{{entrance[0], entrance[1]}}
	n, m := len(maze), len(maze[0])
	res := 0

	maze[entrance[0]][entrance[1]] = '+'

	for len(queue) > 0 {
		for _, curr := range queue {
			queue = queue[1:]
			if (curr.x == n-1 || curr.y == m-1 || curr.x == 0 || curr.y == 0) && (curr.x != entrance[0] || curr.y != entrance[1]) {
				return res
			}

			for _, dir := range []point{{1, 0}, {-1, 0}, {0, 1}, {0, -1}} {
				x, y := curr.x+dir.x, curr.y+dir.y
				if x >= 0 && y >= 0 && x < n && y < m && maze[x][y] != '+' {
					queue = append(queue, point{x, y})
					maze[x][y] = '+'
				}
			}
		}

		res++
	}

	return -1
}
