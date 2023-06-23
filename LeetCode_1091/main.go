/**
  LeetCode_1091
  https://leetcode.com/problems/shortest-path-in-binary-matrix/
  MatrixDeity, 2023.
*/

package leetcode1091

func shortestPathBinaryMatrix(grid [][]int) int {
	n := len(grid)

	if grid[0][0] == 1 || grid[n-1][n-1] == 1 {
		return -1
	}

	visited := make([]bool, n*n)
	queue, next := make([]int, 1, n), make([]int, 0, n)
	steps := 1
	sqr := n*n - 1

	for len(queue) > 0 {
		for _, x := range queue {
			if visited[x] {
				continue
			}

			visited[x] = true

			if x == sqr {
				return steps
			}

			i, j := x/n, x%n
			if grid[i][j] == 1 {
				continue
			}

			if i < n-1 {
				next = append(next, x+n)
				if j < n-1 {
					next = append(next, x+n+1)
				}
				if j > 0 {
					next = append(next, x+n-1)
				}
			}

			if i > 0 {
				next = append(next, x-n)
				if j < n-1 {
					next = append(next, x-n+1)
				}
				if j > 0 {
					next = append(next, x-n-1)
				}
			}

			if j < n-1 {
				next = append(next, x+1)
			}

			if j > 0 {
				next = append(next, x-1)
			}

		}

		queue, next = next, queue[:0]
		steps++
	}

	return -1
}
