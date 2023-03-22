/**
  LeetCode_2187
  https://leetcode.com/problems/minimum-time-to-complete-trips/
  MatrixDeity, 2023.
*/

package leetcode2187

const (
	big int64 = 1e14
)

func minimumTime(time []int, totalTrips int) int64 {
	i, j := int64(1), big

	for i <= j {
		currTotal := 0
		m := i + (j-i)/2

		for _, t := range time {
			currTotal += int(m / int64(t))
		}

		if currTotal >= totalTrips {
			j = m - 1
		} else {
			i = m + 1
		}
	}

	return i
}
