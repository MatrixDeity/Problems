/**
  LeetCode_1293
  https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
  MatrixDeity, 2022.
*/

package leetcode1293

const (
	maxVal int = 1e9
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func shortestPath(grid [][]int, k int) int {
	n := len(grid)
	m := len(grid[0])

	dp := make([][][]int, n)
	for i := range dp {
		dp[i] = make([][]int, m)
		for j := range dp[i] {
			dp[i][j] = make([]int, k+1)
			for r := range dp[i][j] {
				dp[i][j][r] = -1
			}
		}
	}

	visited := make([][]bool, n)
	for i := range visited {
		visited[i] = make([]bool, m)
	}

	var impl func(x, y, currK int) int
	impl = func(x, y, currK int) int {
		if x >= n || x < 0 || y >= m || y < 0 {
			return maxVal
		}

		if visited[x][y] {
			return maxVal
		}

		if dp[x][y][currK] != -1 {
			return dp[x][y][currK]
		}

		if x == 0 && y == 0 {
			dp[x][y][currK] = 0
			return dp[x][y][currK]
		}

		if grid[x][y] == 1 {
			if currK > 0 {
				currK--
			} else {
				dp[x][y][currK] = maxVal
				return dp[x][y][currK]
			}
		}

		visited[x][y] = true
		up := impl(x-1, y, currK) + 1
		left := impl(x, y-1, currK) + 1
		down := impl(x+1, y, currK) + 1
		right := impl(x, y+1, currK) + 1
		visited[x][y] = false

		dp[x][y][currK] = min(up, min(right, min(down, left)))
		return dp[x][y][currK]
	}

	res := impl(n-1, m-1, k)

	if res >= n*m {
		return -1
	}
	return res
}
