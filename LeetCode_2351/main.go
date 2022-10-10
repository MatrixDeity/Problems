/**
  LeetCode_2351
  https://leetcode.com/problems/first-letter-to-appear-twice/
  MatrixDeity, 2022.
*/

package leetcode2351

func repeatedCharacter(s string) byte {
	set := make(map[rune]struct{})
	for _, ch := range s {
		if _, ok := set[ch]; ok {
			return byte(ch)
		}
		set[ch] = struct{}{}
	}
	return 0
}
