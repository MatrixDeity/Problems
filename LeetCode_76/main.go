/**
  LeetCode_76
  https://leetcode.com/problems/minimum-window-substring/
  MatrixDeity, 2022.
*/

package leetcode76

import "math"

func minWindow(s string, t string) string {
	i := 0
	res := ""
	resN := math.MaxInt32

	counter := map[byte]int{}
	for j := range t {
		counter[t[j]]++
	}
	amount := len(counter)

	for j := range s {
		if _, ok := counter[s[j]]; ok {
			counter[s[j]]--
			if counter[s[j]] == 0 {
				amount--
			}
		}

		for amount == 0 {
			if j-i+1 < resN {
				res = s[i : j+1]
				resN = j - i + 1
			}

			if _, ok := counter[s[i]]; ok {
				counter[s[i]]++
				if counter[s[i]] > 0 {
					amount++
				}
			}

			i++
		}
	}

	return res
}
