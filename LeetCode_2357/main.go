/**
  LeetCode_2367
  https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/
  MatrixDeity, 2022.
*/

package leetcode2357

func minimumOperations(nums []int) int {
	set := make(map[int]struct{})
	for _, val := range nums {
		if val != 0 {
			set[val] = struct{}{}
		}
	}
	return len(set)
}
