/**
  LeetCode_1544
  https://leetcode.com/problems/make-the-string-great/
  MatrixDeity, 2022.
*/

package leetcode1544

func makeGood(s string) string {
	stack := make([]byte, 0, len(s))

	d := byte('a' - 'A')
	for i := range s {
		n := len(stack)
		if n > 0 && (s[i] == stack[n-1]-d || s[i]-d == stack[n-1]) {
			stack = stack[:n-1]
		} else {
			stack = append(stack, s[i])
		}
	}

	return string(stack)
}
