/**
  LeetCode_2124
  https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
  MatrixDeity, 2025.
*/

package leetcode2124

func checkString(s string) bool {
	for i := range s {
		if i > 0 && s[i] == 'a' && s[i-1] == 'b' {
			return false
		}
	}

	return true
}
