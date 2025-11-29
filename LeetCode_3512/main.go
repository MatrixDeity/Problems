/**
  LeetCode_3512
  https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
  MatrixDeity, 2025.
*/

package leetcode3512

func minOperations(nums []int, k int) int {
	sum := 0
	for _, num := range nums {
		sum += num
	}

	return sum % k
}
