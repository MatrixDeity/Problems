/**
  LeetCode_1732
  https://leetcode.com/problems/find-the-highest-altitude/
  MatrixDeity, 2023.
*/

package leetcode1732

func largestAltitude(gain []int) int {
	last := 0
	res := 0

	for _, val := range gain {
		last += val
		if res < last {
			res = last
		}
	}

	return res
}
