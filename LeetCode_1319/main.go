/**
  LeetCode_1319
  https://leetcode.com/problems/number-of-operations-to-make-network-connected/
  MatrixDeity, 2023.
*/

package leetcode1319

func makeConnected(n int, connections [][]int) int {
	if len(connections) < n-1 {
		return -1
	}

	graph := make([][]int, n)
	visited := make([]bool, n)

	for _, conn := range connections {
		graph[conn[0]] = append(graph[conn[0]], conn[1])
		graph[conn[1]] = append(graph[conn[1]], conn[0])
	}

	var impl func(vert int)
	impl = func(vert int) {
		visited[vert] = true

		for _, v := range graph[vert] {
			if !visited[v] {
				impl(v)
			}
		}
	}

	count := 0
	for v := range graph {
		if !visited[v] {
			count++
			impl(v)
		}
	}

	return count - 1
}
