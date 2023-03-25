/**
  LeetCode_2316
  https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
  MatrixDeity, 2023.
*/

package leetcode2316

func countPairs(n int, edges [][]int) int64 {
	graph := make([][]int, n)
	visited := make([]bool, n)
	res := int64(0)

	for _, edge := range edges {
		graph[edge[0]] = append(graph[edge[0]], edge[1])
		graph[edge[1]] = append(graph[edge[1]], edge[0])
	}

	var impl func(vert int, cnt *int)
	impl = func(vert int, cnt *int) {
		visited[vert] = true
		*cnt++

		for _, v := range graph[vert] {
			if !visited[v] {
				impl(v, cnt)
			}
		}
	}

	for v := range graph {
		if !visited[v] {
			cnt := 0
			impl(v, &cnt)
			res += int64(cnt) * int64(n-cnt)
		}
	}

	return res / 2
}
