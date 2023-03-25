/**
  LeetCode_2492
  https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
  MatrixDeity, 2023.
*/

package leetcode2492

import "math"

type City struct {
	Vert int
	Dist int
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minScore(n int, roads [][]int) int {
	graph := make([][]City, n+1)
	visited := make([]bool, n+1)
	visited[1] = true

	for _, road := range roads {
		graph[road[0]] = append(graph[road[0]], City{Vert: road[1], Dist: road[2]})
		graph[road[1]] = append(graph[road[1]], City{Vert: road[0], Dist: road[2]})
	}

	var impl func(vert int) int
	impl = func(vert int) int {
		res := math.MaxInt32

		for _, city := range graph[vert] {
			res = min(res, city.Dist)

			if !visited[city.Vert] {
				visited[city.Vert] = true
				res = min(res, impl(city.Vert))
			}
		}

		return res
	}

	return impl(1)
}
