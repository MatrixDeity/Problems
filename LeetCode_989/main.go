/**
  LeetCode_989
  https://leetcode.com/problems/add-to-array-form-of-integer/
  MatrixDeity, 2023.
*/

package leetcode989

func addToArrayForm(num []int, k int) []int {
	rem := 0
	res := make([]int, 0, len(num))

	for i := len(num) - 1; i >= 0 || k > 0 || rem > 0; i-- {
		digK := k % 10

		sum := digK + rem
		if i >= 0 {
			sum += num[i]
		}

		newDig := sum % 10
		rem = sum / 10
		k /= 10
		res = append(res, newDig)
	}

	for i := 0; i < len(res)/2; i++ {
		res[i], res[len(res)-i-1] = res[len(res)-i-1], res[i]
	}

	return res
}
