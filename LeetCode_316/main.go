/**
  LeetCode_316
  https://leetcode.com/problems/remove-duplicate-letters/
  MatrixDeity, 2022.
*/

package leetcode316

func removeDuplicateLetters(s string) string {
	counter := [26]int{}
	visited := [26]bool{}
	res := make([]byte, 0, len(s))

	for i := range s {
		counter[s[i]-'a']++
	}

	for i := range s {
		idx := s[i] - 'a'
		counter[idx]--

		if visited[idx] {
			continue
		}

		for len(res) > 0 && res[len(res)-1] > s[i] && counter[res[len(res)-1]-'a'] > 0 {
			visited[res[len(res)-1]-'a'] = false
			res = res[:len(res)-1]
		}

		res = append(res, s[i])
		visited[idx] = true
	}

	return string(res)
}
