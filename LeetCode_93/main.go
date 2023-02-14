/**
  LeetCode_93
  https://leetcode.com/problems/restore-ip-addresses/
  MatrixDeity, 2023.
*/

package leetcode93

import (
	"strconv"
	"strings"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func isValid(s string) bool {
	if len(s) > 1 && s[0] == '0' {
		return false
	}

	if num, _ := strconv.Atoi(s); num > 255 {
		return false
	}

	return true
}

func restoreIpAddresses(s string) []string {
	res := []string{}

	var impl func(curr string, builder []string)
	impl = func(curr string, builder []string) {
		n := len(curr)
		if n == 0 && len(builder) == 4 {
			res = append(res, strings.Join(builder, "."))
			return
		}

		for i := 1; i <= min(n, 3); i++ {
			if isValid(curr[0:i]) {
				impl(curr[i:], append(builder, curr[0:i]))
			}
		}
	}

	impl(s, []string{})

	return res
}
