/**
  LeetCode_839
  https://leetcode.com/problems/similar-string-groups/
  MatrixDeity, 2023.
*/

package leetcode839

func isSimilar(a, b string) bool {
	bads := 0

	for i := range a {
		if a[i] != b[i] {
			bads++

			if bads > 2 {
				return false
			}
		}
	}

	return bads == 0 || bads == 2
}

func numSimilarGroups(strs []string) int {
	n := len(strs)
	graph := make([][]int, n)
	visited := make([]bool, n)
	res := 0

	for i := range strs {
		for j := range strs {
			if isSimilar(strs[j], strs[i]) {
				graph[i] = append(graph[i], j)
				graph[j] = append(graph[j], i)
			}
		}
	}

	var impl func(vert int)
	impl = func(vert int) {
		visited[vert] = true

		for _, v := range graph[vert] {
			if !visited[v] {
				impl(v)
			}
		}
	}

	for i := range strs {
		if !visited[i] {
			impl(i)
			res++
		}
	}

	return res
}
