/**
  LeetCode_1626
  https://leetcode.com/problems/best-team-with-no-conflicts/
  MatrixDeity, 2023.
*/

package leetcode1626

import (
	"sort"
)

type player struct {
	score int
	age   int
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func bestTeamScore(scores []int, ages []int) int {
	dp := make(map[int]map[int]int)
	graph := make([]player, 0, len(scores))

	var impl func(i, age int) int
	impl = func(i, age int) int {
		if i == len(graph) {
			return 0
		}

		if _, ok := dp[i]; !ok {
			dp[i] = map[int]int{}
		}

		if val, ok := dp[i][age]; ok {
			return val
		}

		res := impl(i+1, age)

		if graph[i].age >= age {
			subScore := impl(i+1, graph[i].age)
			res = max(res, graph[i].score+subScore)
		}

		dp[i][age] = res
		return res
	}

	for i := range scores {
		graph = append(graph, player{score: scores[i], age: ages[i]})
	}

	sort.Slice(graph, func(i, j int) bool {
		if graph[i].score == graph[j].score {
			return graph[i].age < graph[j].age
		}
		return graph[i].score < graph[j].score
	})

	return impl(0, 0)
}
