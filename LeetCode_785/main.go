/**
  LeetCode_785
  https://leetcode.com/problems/is-graph-bipartite/
  MatrixDeity, 2023.
*/

package leetcode785

func isBipartite(graph [][]int) bool {
	n := len(graph)
	colors := make([]int, n)

	var impl func(i int) bool
	impl = func(i int) bool {
		for _, v := range graph[i] {
			if colors[v] == 0 {
				colors[v] = -colors[i]
				if !impl(v) {
					return false
				}
			} else if colors[v] == colors[i] {
				return false
			}
		}

		return true
	}

	for i := 0; i < n; i++ {
		if colors[i] != 0 {
			continue
		}

		colors[i] = 1
		if !impl(i) {
			return false
		}
	}

	return true
}
