/**
  LeetCode_13
  https://leetcode.com/problems/roman-to-integer/
  MatrixDeity, 2022.
*/

package leetcode13

func romanToInt(s string) int {
	res := 0
	pattern := map[byte]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}
	n := len(s)

	for i := range s {
		num := pattern[s[i]]
		if i < n-1 && num < pattern[s[i+1]] {
			res -= num
		} else {
			res += num
		}
	}

	return res
}
