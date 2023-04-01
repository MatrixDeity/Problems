/**
  LeetCode_2360
  https://leetcode.com/problems/longest-cycle-in-a-graph/
  MatrixDeity, 2023.
*/

package leetcode2360

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func longestCycle(edges []int) int {
	visited := make([]bool, len(edges))
	res := -1

	var impl func(vert int, distMap map[int]int)
	impl = func(vert int, distMap map[int]int) {
		visited[vert] = true

		target := edges[vert]

		if target != -1 && !visited[target] {
			distMap[target] = distMap[vert] + 1
			impl(edges[vert], distMap)
		} else if _, ok := distMap[target]; ok {
			res = max(res, distMap[vert]-distMap[target]+1)
		}
	}

	for v := range edges {
		if !visited[v] {
			distMap := make(map[int]int)
			distMap[v] = 1
			impl(v, distMap)
		}
	}

	return res
}
