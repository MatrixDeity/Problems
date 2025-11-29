/**
  LeetCode_3190
  https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
  MatrixDeity, 2025.
*/

package leetcode3190

func minimumOperations(nums []int) int {
	res := 0

	for _, num := range nums {
		if num%3 != 0 {
			res++
		}
	}

	return res
}
