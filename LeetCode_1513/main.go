/**
  LeetCode_1513
  https://leetcode.com/problems/number-of-substrings-with-only-1s/
  MatrixDeity, 2025.
*/

package leetcode1513

func numSub(s string) int {
	const mod = 1e9 + 7

	count, res := 0, 0
	for _, c := range s {
		if c == '0' {
			res += count * (count + 1) / 2 % mod
			count = 0
		} else {
			count++
		}
	}
	res += count * (count + 1) / 2 % mod

	return res
}
