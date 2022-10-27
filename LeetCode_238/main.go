/**
  LeetCode_238
  https://leetcode.com/problems/product-of-array-except-self/
  MatrixDeity, 2022.
*/

package leetcode238

func productExceptSelf(nums []int) []int {
	res := make([]int, len(nums))
	zeros := 0
	mult := 0

	for _, num := range nums {
		if num != 0 {
			if mult == 0 {
				mult = 1
			}
			mult *= num
		} else {
			zeros++
		}
	}

	for i, num := range nums {
		if zeros > 0 {
			if num != 0 || zeros > 1 {
				res[i] = 0
			} else {
				res[i] = mult
			}
		} else {
			res[i] = mult / num
		}
	}

	return res
}
