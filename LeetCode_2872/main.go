/**
  LeetCode_2872
  https://leetcode.com/problems/maximum-number-of-k-divisible-components/
  MatrixDeity, 2025.
*/

package leetcode2872

func maxKDivisibleComponents(n int, edges [][]int, values []int, k int) int {
	adj := make([][]int, n)
	for _, edge := range edges {
		adj[edge[0]] = append(adj[edge[0]], edge[1])
		adj[edge[1]] = append(adj[edge[1]], edge[0])
	}

	res := 0
	var dfs func(node, parent int) int
	dfs = func(node, parent int) int {
		s := values[node]

		for _, next := range adj[node] {
			if next != parent {
				s += dfs(next, node)
			}
		}
		if s%k == 0 {
			res += 1
		}

		return s % k
	}

	dfs(0, -1)

	return res
}
