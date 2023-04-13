/**
  LeetCode_2439
  https://leetcode.com/problems/minimize-maximum-of-array/
  MatrixDeity, 2023.
*/

package leetcode2439

func minimizeArrayValue(nums []int) int {
	res, sum := 0, 0

	for i, num := range nums {
		sum += num
		avg := (sum + i) / (i + 1)

		if avg > res {
			res = avg
		}
	}

	return res
}
