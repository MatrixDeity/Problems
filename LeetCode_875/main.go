/**
  LeetCode_875
  https://leetcode.com/problems/koko-eating-bananas/
  MatrixDeity, 2023.
*/

package leetcode875

const (
	big int = 1e10
)

func minEatingSpeed(piles []int, h int) int {
	i, j := 1, big

	for i <= j {
		m := i + (j-i)/2
		currH := 0

		for _, pile := range piles {
			currH += (pile + m - 1) / m
		}

		if currH > h {
			i = m + 1
		} else {
			j = m - 1
		}
	}

	return i
}
