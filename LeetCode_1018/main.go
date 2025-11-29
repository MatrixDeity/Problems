/**
  LeetCode_1018
  https://leetcode.com/problems/binary-prefix-divisible-by-5/
  MatrixDeity, 2025.
*/

package leetcode1018

func prefixesDivBy5(nums []int) []bool {
	res := make([]bool, 0, len(nums))
	x := 0

	for _, num := range nums {
		x = (x | num) % 5
		res = append(res, x == 0)
		x <<= 1
	}

	return res
}
