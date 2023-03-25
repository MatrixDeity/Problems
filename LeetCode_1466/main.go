/**
  LeetCode_1466
  https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
  MatrixDeity, 2023.
*/

package leetcode1466

type City struct {
	To   int
	Dist int
}

func minReorder(n int, connections [][]int) int {
	graph := make([][]City, n)

	for _, conn := range connections {
		graph[conn[0]] = append(graph[conn[0]], City{To: conn[1], Dist: 1})
		graph[conn[1]] = append(graph[conn[1]], City{To: conn[0], Dist: 0})
	}

	var impl func(i, parent int) int
	impl = func(i, parent int) int {
		res := 0

		for _, city := range graph[i] {
			if city.To == parent {
				continue
			}

			res += city.Dist
			res += impl(city.To, i)
		}

		return res
	}

	return impl(0, -1)
}
