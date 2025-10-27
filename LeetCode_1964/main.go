/**
  LeetCode_1964
  https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
  MatrixDeity, 2023.
*/

package leetcode1964

func binsearch(nums []int, target int) int {
	i, j := 0, len(nums)-1

	for i <= j {
		m := i + (j-i)/2

		if nums[m] <= target {
			i = m + 1
		} else {
			j = m - 1
		}
	}

	return i
}

func longestObstacleCourseAtEachPosition(obstacles []int) []int {
	n := len(obstacles)
	sub := make([]int, 0, n)
	res := make([]int, 0, n)

	for _, obst := range obstacles {
		i := binsearch(sub, obst)

		if i == len(sub) {
			sub = append(sub, obst)
		} else {
			sub[i] = obst
		}

		res = append(res, i+1)
	}

	return res
}
