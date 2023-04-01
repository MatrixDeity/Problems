/**
  LeetCode_87
  https://leetcode.com/problems/scramble-string/
  MatrixDeity, 2023.
*/

package leetcode87

import "fmt"

func isScramble(s1 string, s2 string) bool {
	dp := make(map[string]bool)

	var impl func(i, j, currLen int) bool
	impl = func(i, j, currLen int) bool {
		if currLen == 1 {
			return s1[i] == s2[j]
		}

		key := fmt.Sprintf("%d/%d/%d", i, j, currLen)
		if val, ok := dp[key]; ok {
			return val
		}

		for k := 1; k < currLen; k++ {
			if (impl(i, j, k) && impl(i+k, j+k, currLen-k)) || (impl(i, j+currLen-k, k) && impl(i+k, j, currLen-k)) {
				dp[key] = true
				return dp[key]
			}
		}

		dp[key] = false
		return dp[key]
	}

	return impl(0, 0, len(s1))
}
