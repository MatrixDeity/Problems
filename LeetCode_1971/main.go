/**
  LeetCode_1971
  https://leetcode.com/problems/find-if-path-exists-in-graph/description/
  MatrixDeity, 2022.
*/

package leetcode1971

func validPath(n int, edges [][]int, source int, destination int) bool {
	graph := make([]map[int]struct{}, n)
	visited := map[int]struct{}{}

	for _, edge := range edges {
		if graph[edge[0]] == nil {
			graph[edge[0]] = map[int]struct{}{}
		}
		if graph[edge[1]] == nil {
			graph[edge[1]] = map[int]struct{}{}
		}

		graph[edge[0]][edge[1]] = struct{}{}
		graph[edge[1]][edge[0]] = struct{}{}
	}

	var impl func(v int) bool
	impl = func(v int) bool {
		if _, ok := visited[v]; ok {
			return false
		}

		visited[v] = struct{}{}

		if v == destination {
			return true
		}

		res := false
		for i := range graph[v] {
			res = res || impl(i)
		}

		return res
	}

	return impl(source)
}
