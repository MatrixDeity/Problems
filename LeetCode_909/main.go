/**
  LeetCode_909
  https://leetcode.com/problems/snakes-and-ladders/
  MatrixDeity, 2023.
*/

package leetcode909

func snakesAndLadders(board [][]int) int {
	n := len(board)
	dp := map[int]int{}
	dp[1] = 0
	queue := []int{1}

	for i := 0; i < len(queue); i++ {
		pos := queue[i]

		for j := pos + 1; j < pos+7; j++ {
			x, y := (j-1)/n, (j-1)%n

			next := board[len(board)-x-1][y]
			if x%2 == 1 {
				next = board[len(board)-x-1][len(board)-y-1]
			}

			target := j
			if next > 0 {
				target = next
			}

			if target == n*n {
				return dp[pos] + 1
			}

			if _, ok := dp[target]; !ok {
				dp[target] = dp[pos] + 1
				queue = append(queue, target)
			}
		}

	}

	return -1
}
