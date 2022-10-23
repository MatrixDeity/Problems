/**
  LeetCode_1578
  https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
  MatrixDeity, 2022.
*/

package leetcode1578

func minCost(colors string, neededTime []int) int {
	res := 0
	n := len(colors)

	for i := 1; i < n; i++ {
		if colors[i] == colors[i-1] {
			if neededTime[i] < neededTime[i-1] {
				neededTime[i], neededTime[i-1] = neededTime[i-1], neededTime[i]
			}
			res += neededTime[i-1]
		}
	}

	return res
}
