/**
  LeetCode_1704
  https://leetcode.com/problems/determine-if-string-halves-are-alike/
  MatrixDeity, 2022.
*/

package leetcode1704

func halvesAreAlike(s string) bool {
	n := len(s)
	vowels := map[byte]bool{
		'a': true,
		'A': true,
		'e': true,
		'E': true,
		'i': true,
		'I': true,
		'o': true,
		'O': true,
		'u': true,
		'U': true,
	}

	lCnt, rCnt := 0, 0
	for i := 0; i < n/2; i++ {
		if vowels[s[i]] {
			lCnt++
		}
		if vowels[s[n-i-1]] {
			rCnt++
		}
	}

	return lCnt == rCnt
}
