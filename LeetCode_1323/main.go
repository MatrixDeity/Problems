/**
  LeetCode_1323
  https://leetcode.com/problems/maximum-69-number/
  MatrixDeity, 2022.
*/

package leetcode1323

func maximum69Number(num int) int {
	res, resMult, mult := num, 0, 1

	for num > 0 {
		d := num % 10
		if d == 6 {
			resMult = mult
		}
		mult *= 10
		num /= 10
	}

	if resMult > 0 {
		res += 3 * resMult
	}

	return res
}
