/**
  LeetCode_1162
  https://leetcode.com/problems/as-far-from-land-as-possible/
  MatrixDeity, 2023.
*/

package leetcode1162

func maxDistance(grid [][]int) int {
	n, m := len(grid), len(grid[0])
	queue := [][]int{}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == 1 {
				queue = append(queue, []int{i, j})
			}
		}
	}

	if len(queue) == n*m {
		return -1
	}

	res := -1
	dirs := [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}

	for len(queue) > 0 {
		res++
		k := len(queue)
		for i := 0; i < k; i++ {
			curr := queue[0]
			queue = queue[1:]

			for _, dir := range dirs {
				x := curr[0] + dir[0]
				y := curr[1] + dir[1]
				if x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 1 {
					continue
				}

				grid[x][y] = 1
				queue = append(queue, []int{x, y})
			}
		}
	}

	return res
}
