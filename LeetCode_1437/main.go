/**
  LeetCode_1437
  https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
  MatrixDeity, 2025.
*/

package leetcode1437

func kLengthApart(nums []int, k int) bool {
	var i int = -1e9

	for j, num := range nums {
		if num == 1 {
			if j-i-1 < k {
				return false
			}
			i = j
		}
	}

	return true
}
