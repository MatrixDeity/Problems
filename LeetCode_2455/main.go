/**
  LeetCode_2455
  https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/
  MatrixDeity, 2022.
*/

package leetcode2455

func averageValue(nums []int) int {
	res, n := 0, 0

	for _, num := range nums {
		if num%2 == 0 && num%3 == 0 {
			res += num
			n++
		}
	}

	if n == 0 {
		return 0
	}
	return res / n
}
