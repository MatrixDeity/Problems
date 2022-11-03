/**
  LeetCode_1706
  https://leetcode.com/problems/where-will-the-ball-fall/
  MatrixDeity, 2022.
*/

package leetcode1706

func findBall(grid [][]int) []int {
	n := len(grid)
	m := len(grid[0])
	res := make([]int, m)

	for j := 0; j < m; j++ {
		curr := j
		for i := 0; i < n; i++ {
			next := curr + grid[i][curr]
			if next < 0 || next >= m || grid[i][curr] != grid[i][next] {
				curr = -1
				break
			}
			curr = next
		}
		res[j] = curr
	}

	return res
}
