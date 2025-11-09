/**
  LeetCode_1716
  https://leetcode.com/problems/calculate-money-in-leetcode-bank/
  MatrixDeity, 2025.
*/

package leetcode1716

func totalMoney(n int) int {
	w, d := n/7, n%7
	wBase := w * (7 * 8) / 2
	wAdd := (w * (w - 1)) / 2 * 7
	dBase := (d * (d + 1)) / 2
	dAdd := w * d

	return wBase + wAdd + dBase + dAdd
}
