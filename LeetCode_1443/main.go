/**
  LeetCode_1443
  https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
  MatrixDeity, 2023.
*/

package leetcode1443

func minTime(n int, edges [][]int, hasApple []bool) int {
	graph := map[int][]int{}

	for _, edge := range edges {
		if graph[edge[0]] == nil {
			graph[edge[0]] = []int{}
		}
		if graph[edge[1]] == nil {
			graph[edge[1]] = []int{}
		}

		graph[edge[0]] = append(graph[edge[0]], edge[1])
		graph[edge[1]] = append(graph[edge[1]], edge[0])
	}

	var impl func(node, prev, lvl int) int
	impl = func(node, prev, lvl int) int {
		pathSum := 0

		for _, val := range graph[node] {
			if val != prev {
				path := impl(val, node, lvl+1)
				if path > 0 {
					pathSum += path - lvl
				}
			}
		}

		if pathSum == 0 && !hasApple[node] {
			return 0
		}
		return pathSum + lvl
	}

	return impl(0, -1, 0) * 2
}
