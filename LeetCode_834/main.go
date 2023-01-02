/**
  LeetCode_834
  https://leetcode.com/problems/sum-of-distances-in-tree/description/
  MatrixDeity, 2022.
*/

package leetcode834

func sumOfDistancesInTree(n int, edges [][]int) []int {
	graph := make([][]int, n)
	for _, edge := range edges {
		graph[edge[0]] = append(graph[edge[0]], edge[1])
		graph[edge[1]] = append(graph[edge[1]], edge[0])
	}

	res, counter := make([]int, n), make([]int, n)

	var postDfs func(node, parent int)
	postDfs = func(node, parent int) {
		for _, dest := range graph[node] {
			if dest != parent {
				postDfs(dest, node)
				res[node] += res[dest] + counter[dest]
				counter[node] += counter[dest]
			}
		}
		counter[node]++
	}

	var preDfs func(node, parent int)
	preDfs = func(node, parent int) {
		for _, dest := range graph[node] {
			if dest != parent {
				res[dest] = res[node] - counter[dest] + n - counter[dest]
				preDfs(dest, node)
			}
		}
	}

	postDfs(0, -1)
	preDfs(0, -1)

	return res
}
