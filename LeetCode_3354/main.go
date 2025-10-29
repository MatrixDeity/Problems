/**
  LeetCode_3354
  https://leetcode.com/problems/make-array-elements-equal-to-zero/
  MatrixDeity, 2025.
*/

package leetcode3354

func countValidSelections(nums []int) int {
	leftSum, rightSum := 0, 0
	res := 0
	for _, n := range nums {
		rightSum += n
	}

	for _, n := range nums {
		leftSum += n
		rightSum -= n
		if n == 0 {
			if leftSum == rightSum {
				res += 2
			} else if abs(leftSum-rightSum) == 1 {
				res++
			}
		}
	}

	return res
}

func abs(n int) int {
	if n < 0 {
		return -n
	}

	return n
}
