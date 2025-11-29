/**
  LeetCode_1930
  https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
  MatrixDeity, 2025.
*/

package leetcode1930

func countPalindromicSubsequence(s string) int {
	first := make(map[byte]int, len(s))
	last := make(map[byte]int, len(s))
	res := 0

	for i := range s {
		last[s[i]] = i
		if _, ok := first[s[i]]; !ok {
			first[s[i]] = i
		}
	}

	for c, i := range first {
		j := last[c]
		set := make(map[byte]struct{}, len(first))

		for k := i + 1; k < j; k++ {
			set[s[k]] = struct{}{}
		}

		res += len(set)
	}

	return res
}
