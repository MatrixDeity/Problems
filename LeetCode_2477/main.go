/**
  LeetCode_2477
  https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/
  MatrixDeity, 2023.
*/

package leetcode2477

func minimumFuelCost(roads [][]int, seats int) int64 {
	res := int64(0)
	graph := map[int][]int{}

	for _, road := range roads {
		if graph[road[0]] == nil {
			graph[road[0]] = []int{}
		}
		if graph[road[1]] == nil {
			graph[road[1]] = []int{}
		}

		graph[road[0]] = append(graph[road[0]], road[1])
		graph[road[1]] = append(graph[road[1]], road[0])
	}

	var impl func(node, parent int) int
	impl = func(node, parent int) int {
		fuel := 1
		for _, i := range graph[node] {
			if i != parent {
				fuel += impl(i, node)
			}
		}

		if node > 0 {
			res += int64((fuel-1)/seats + 1)
		}

		return fuel
	}

	impl(0, -1)

	return res
}
