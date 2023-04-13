/**
  LeetCode_1857
  https://leetcode.com/problems/largest-color-value-in-a-directed-graph/
  MatrixDeity, 2023.
*/

package leetcode1857

func largestPathValue(colors string, edges [][]int) int {
	n := len(colors)
	graph := make([][]int, n)
	dp := make([][26]int, n)
	inDegree := make([]int, n)
	zeros := []int{}
	removed, res := 0, 0

	for _, edge := range edges {
		graph[edge[0]] = append(graph[edge[0]], edge[1])
		inDegree[edge[1]]++
	}

	for i := 0; i < n; i++ {
		if inDegree[i] == 0 {
			zeros = append(zeros, i)
		}
	}

	for len(zeros) > 0 {
		currV := zeros[0]
		zeros = zeros[1:]
		color := colors[currV] - 'a'

		removed++
		dp[currV][color]++

		if res < dp[currV][color] {
			res = dp[currV][color]
		}

		for _, v := range graph[currV] {
			inDegree[v]--

			if inDegree[v] == 0 {
				zeros = append(zeros, v)
			}

			for c := 0; c < 26; c++ {
				if dp[v][c] < dp[currV][c] {
					dp[v][c] = dp[currV][c]
				}
			}
		}
	}

	if removed < n {
		return -1
	}

	return res
}
