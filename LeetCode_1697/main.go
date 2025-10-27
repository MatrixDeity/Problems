/**
  LeetCode_1697
  https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/
  MatrixDeity, 2023.
*/

package leetcode1697

import "sort"

func distanceLimitedPathsExist(n int, edgeList [][]int, queries [][]int) []bool {
	parents := make([]int, n)
	for i := 0; i < n; i++ {
		parents[i] = i
	}

	var find func(x int) int
	find = func(x int) int {
		if parents[x] != x {
			parents[x] = find(parents[x])
		}

		return parents[x]
	}

	union := func(a, b int) {
		a = find(a)
		b = find(b)

		if a != b {
			parents[a] = b
		}
	}

	sort.Slice(edgeList, func(i, j int) bool {
		return edgeList[i][2] < edgeList[j][2]
	})

	for i, query := range queries {
		queries[i] = append(query, i)
	}

	sort.Slice(queries, func(i, j int) bool {
		return queries[i][2] < queries[j][2]
	})

	res := make([]bool, len(queries))
	edgeIdx := 0
	for _, query := range queries {
		p, q, limit, idx := query[0], query[1], query[2], query[3]

		for edgeIdx < len(edgeList) && edgeList[edgeIdx][2] < limit {
			union(edgeList[edgeIdx][0], edgeList[edgeIdx][1])
			edgeIdx++
		}

		res[idx] = find(p) == find(q)
	}

	return res
}
