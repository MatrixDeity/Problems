/**
  LeetCode_452
  https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
  MatrixDeity, 2023.
*/

package leetcode452

import "sort"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func findMinArrowShots(points [][]int) int {
	res := 1
	last := points[0][1]

	sort.Slice(points, func(i, j int) bool {
		if points[i][0] == points[j][0] {
			return points[i][1] < points[j][1]
		}
		return points[i][0] < points[j][0]
	})

	for _, point := range points {
		if point[0] > last {
			last = point[1]
			res++
		}
		last = min(point[1], last)
	}

	return res
}
