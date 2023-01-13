/**
  LeetCode_1519
  https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
  MatrixDeity, 2023.
*/

package leetcode1519

func countSubTrees(n int, edges [][]int, labels string) []int {
	res := make([]int, n)
	graph := make([][]int, n)
	counter := map[byte]int{}

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

	var impl func(vert, prev int)
	impl = func(vert, prev int) {
		prevSum := counter[labels[vert]]
		counter[labels[vert]]++

		for _, v := range graph[vert] {
			if v != prev {
				impl(v, vert)
			}
		}

		res[vert] = counter[labels[vert]] - prevSum
	}

	impl(0, -1)
	return res
}
