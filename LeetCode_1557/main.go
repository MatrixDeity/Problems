/**
  LeetCode_1557
  https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
  MatrixDeity, 2023.
*/

package leetcode1557

func findSmallestSetOfVertices(n int, edges [][]int) []int {
	res := make([]int, 0, n)
	visited := make([]bool, n)

	for _, edge := range edges {
		visited[edge[1]] = true
	}

	for vertex := 0; vertex < n; vertex++ {
		if !visited[vertex] {
			res = append(res, vertex)
		}
	}

	return res
}
