/**
  LeetCode_57
  https://leetcode.com/problems/insert-interval/
  MatrixDeity, 2023.
*/

package leetcode57

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func insert(intervals [][]int, newInterval []int) [][]int {
	n := len(intervals)
	res := make([][]int, 0, n+1)

	for i := range intervals {
		if newInterval[1] < intervals[i][0] {
			res = append(res, newInterval)
			res = append(res, intervals[i:]...)
			return res
		} else if newInterval[0] > intervals[i][1] {
			res = append(res, intervals[i])
		} else {
			newInterval = []int{min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])}
		}
	}

	res = append(res, newInterval)

	return res
}
