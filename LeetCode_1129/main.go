/**
  LeetCode_1129
  https://leetcode.com/problems/shortest-path-with-alternating-colors/
  MatrixDeity, 2023.
*/

package leetcode1129

const (
	blue = 1
	red  = -1
)

type node struct {
	number int
	color  int
}

func shortestAlternatingPaths(n int, red_edges [][]int, blue_edges [][]int) []int {
	res := make([]int, n)
	for i := range res {
		res[i] = -1
	}
	res[0] = 0

	graph := make([][]node, n)
	for _, edge := range red_edges {
		graph[edge[0]] = append(graph[edge[0]], node{edge[1], -1})
	}
	for _, edge := range blue_edges {
		graph[edge[0]] = append(graph[edge[0]], node{edge[1], 1})
	}

	var impl func(color int)
	impl = func(color int) {
		queue := []node{{0, color}}
		visited := make(map[int][]bool)
		visited[blue] = make([]bool, n)
		visited[red] = make([]bool, n)
		dist := 0

		for len(queue) > 0 {
			dist++
			k := len(queue)
			for i := 0; i < k; i++ {
				node := queue[0]
				queue = queue[1:]

				for _, neighbor := range graph[node.number] {
					if neighbor.color != -node.color || visited[neighbor.color][neighbor.number] {
						continue
					}

					visited[neighbor.color][neighbor.number] = true
					queue = append(queue, neighbor)

					if dist < res[neighbor.number] || res[neighbor.number] == -1 {
						res[neighbor.number] = dist
					}
				}
			}
		}
	}

	impl(blue)
	impl(red)

	return res
}
