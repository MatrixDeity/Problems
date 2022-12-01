/**
  LeetCode_1235
  https://leetcode.com/problems/maximum-profit-in-job-scheduling/
  MatrixDeity, 2022.
*/

package leetcode1235

import "sort"

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func jobScheduling(startTime []int, endTime []int, profit []int) int {
	n := len(startTime)
	jobs := make([][3]int, 0, n)
	dp := make([]int, n)

	for i := range startTime {
		jobs = append(jobs, [3]int{startTime[i], endTime[i], profit[i]})
		dp[i] = -1
	}
	sort.Slice(jobs, func(i, j int) bool {
		return jobs[i][0] < jobs[j][0]
	})

	var impl func(i int) int
	impl = func(i int) int {
		if i == n {
			return 0
		}

		if dp[i] != -1 {
			return dp[i]
		}

		prof1 := impl(i + 1)

		l, r := i+1, n
		for l < r {
			mid := l + (r-l)/2

			if jobs[mid][0] < jobs[i][1] {
				l = mid + 1
			} else {
				r = mid
			}
		}
		prof2 := jobs[i][2] + impl(l)

		dp[i] = max(prof1, prof2)
		return dp[i]
	}

	return impl(0)
}
