/**
  LeetCode_131
  https://leetcode.com/problems/palindrome-partitioning/
  MatrixDeity, 2023.
*/

package leetcode131

func isPalid(s string) bool {
	n := len(s)
	for i := 0; i < n/2; i++ {
		if s[i] != s[n-i-1] {
			return false
		}
	}
	return true
}

func partition(s string) [][]string {
	res := [][]string{}
	curr := []string{}
	n := len(s)

	var impl func(i int)
	impl = func(i int) {
		if i == n {
			tmp := make([]string, len(curr))
			copy(tmp, curr)
			res = append(res, tmp)
			return
		}

		for j := i; j < n; j++ {
			str := s[i : j+1]
			if isPalid(str) {
				curr = append(curr, str)
				impl(j + 1)
				curr = curr[:len(curr)-1]
			}
		}
	}

	impl(0)

	return res
}
