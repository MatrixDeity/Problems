/**
  LeetCode_1526
  https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
  MatrixDeity, 2025.
*/

package leetcode1526

func minNumberOperations(target []int) int {
	res := 0
	prev := 0

	for _, n := range target {
		if prev < n {
			res += n - prev
		}
		prev = n
	}

	return res
}
