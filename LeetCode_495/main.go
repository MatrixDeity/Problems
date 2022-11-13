/**
  LeetCode_495
  https://leetcode.com/problems/teemo-attacking/
  MatrixDeity, 2022.
*/

package leetcode495

func findPoisonedDuration(timeSeries []int, duration int) int {
	res := 0

	for i := 0; i < len(timeSeries)-1; i++ {
		if timeSeries[i]+duration > timeSeries[i+1] {
			res += timeSeries[i+1] - timeSeries[i]
		} else {
			res += duration
		}
	}
	res += duration

	return res
}
