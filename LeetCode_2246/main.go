/**
  LeetCode_2246
  https://leetcode.com/problems/longest-path-with-different-adjacent-characters/
  MatrixDeity, 2023.
*/

package leetcode2246

func longestPath(parent []int, s string) int {
	res := 0
	graph := map[int][]int{}
	n := len(parent)

	for i := 1; i < n; i++ {
		if graph[parent[i]] == nil {
			graph[parent[i]] = []int{}
		}

		graph[parent[i]] = append(graph[parent[i]], i)
	}

	var impl func(vert int) int
	impl = func(vert int) int {
		path1, path2 := 0, 0

		for _, v := range graph[vert] {
			path := impl(v)
			if s[v] != s[vert] {
				if path > path2 {
					path2 = path
				}
				if path2 > path1 {
					path1, path2 = path2, path1
				}
			}
		}

		fullPath := path1 + path2 + 1
		if res < fullPath {
			res = fullPath
		}

		return path1 + 1
	}

	impl(0)
	return res
}
