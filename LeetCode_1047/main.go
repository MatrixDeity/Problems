/**
  LeetCode_1047
  https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
  MatrixDeity, 2022.
*/

package leetcode1047

func removeDuplicates(s string) string {
	stack := make([]byte, 0, len(s))

	for i := range s {
		n := len(stack)
		if n > 0 && stack[n-1] == s[i] {
			stack = stack[:n-1]
		} else {
			stack = append(stack, s[i])
		}
	}

	return string(stack)
}
