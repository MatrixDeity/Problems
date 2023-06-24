/**
  LeetCode_1376
  https://leetcode.com/problems/time-needed-to-inform-all-employees/
  MatrixDeity, 2023.
*/

package leetcode1376

import "math"

func numOfMinutes(n int, headID int, manager []int, informTime []int) int {
	res := math.MinInt
	graph := make([][]int, n)

	for i := 0; i < len(manager); i++ {
		if manager[i] != -1 {
			graph[manager[i]] = append(graph[manager[i]], i)
		}
	}

	var impl func(i, sum int)
	impl = func(i, sum int) {
		if sum > res {
			res = sum
		}

		for _, v := range graph[i] {
			impl(v, sum+informTime[i])
		}
	}

	impl(headID, 0)

	return res
}
