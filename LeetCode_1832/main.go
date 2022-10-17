/**
  LeetCode_1832
  https://leetcode.com/problems/check-if-the-sentence-is-pangram/
  MatrixDeity, 2022.
*/

package leetcode1832

func checkIfPangram(sentence string) bool {
	cntr := make([]rune, 26)
	for _, ch := range sentence {
		cntr[ch-'a']++
	}

	for _, cnt := range cntr {
		if cnt == 0 {
			return false
		}
	}

	return true
}
