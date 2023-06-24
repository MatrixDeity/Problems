/**
  LeetCode_1456
  https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
  MatrixDeity, 2023.
*/

package leetcode1456

func isVowel(char byte) bool {
	switch char {
	case 'a', 'e', 'i', 'o', 'u':
		return true
	}

	return false
}

func maxVowels(s string, k int) int {
	res, curr := 0, 0
	n := len(s)

	for i := 0; i < n; i++ {
		if isVowel(s[i]) {
			curr++
		}

		if i >= k && isVowel(s[i-k]) {
			curr--
		}

		if curr > res {
			res = curr
		}
	}

	return res
}
