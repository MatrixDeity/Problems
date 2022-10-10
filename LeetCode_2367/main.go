/**
  LeetCode_2367
  https://leetcode.com/problems/number-of-arithmetic-triplets/
  MatrixDeity, 2022.
*/

package leetcode2367

func arithmeticTriplets(nums []int, diff int) int {
	res := 0
	set := make(map[int]struct{})
	for _, num := range nums {
		if _, ok := set[num-diff]; ok {
			if _, ok := set[num-2*diff]; ok {
				res++
			}
		}
		set[num] = struct{}{}
	}
	return res
}
