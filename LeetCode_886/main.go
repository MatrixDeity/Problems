/**
  LeetCode_886
  https://leetcode.com/problems/possible-bipartition/
  MatrixDeity, 2022.
*/

package leetcode886

func possibleBipartition(n int, dislikes [][]int) bool {
	colors := make([]int, n+1)
	graph := make([][]int, n+1)
	res := true

	for i := range graph {
		graph[i] = make([]int, 0, n+1)
	}

	for _, pair := range dislikes {
		graph[pair[0]] = append(graph[pair[0]], pair[1])
		graph[pair[1]] = append(graph[pair[1]], pair[0])
	}

	var impl func(vertex, color int) bool
	impl = func(vertex, color int) bool {
		if colors[vertex] != 0 {
			return colors[vertex] == color
		}

		colors[vertex] = color

		for _, v := range graph[vertex] {
			if !impl(v, -color) {
				return false
			}
		}
		return true
	}

	for i := 1; i <= n; i++ {
		if colors[i] == 0 {
			res = res && impl(i, 1)
		}
	}

	return res
}
