/**
  LeetCode_757
  https://leetcode.com/problems/set-intersection-size-at-least-two/
  MatrixDeity, 2025.
*/

package leetcode757

import "sort"

func intersectionSizeTwo(intervals [][]int) int {
	n := len(intervals)
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][1] == intervals[j][1] {
			return intervals[i][0] > intervals[j][0]
		}
		return intervals[i][1] < intervals[j][1]
	})

	res := 2
	a, b := intervals[0][1]-1, intervals[0][1]
	for i := 1; i < n; i++ {
		l, r := intervals[i][0], intervals[i][1]
		if a >= l {
			continue
		}

		if l > b {
			res++
			a = r - 1
		} else {
			a = b
		}
		b = r
		res++
	}

	return res
}
