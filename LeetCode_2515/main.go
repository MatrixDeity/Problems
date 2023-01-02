/**
  LeetCode_2515
  https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
  MatrixDeity, 2023.
*/

package leetcode2515

const (
	big int = 1e9
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func closetTarget(words []string, target string, startIndex int) int {
	res := big
	n := len(words)

	for i := 0; i < n; i++ {
		if words[i] == target {
			res = min(min(abs(i-startIndex), n-abs(i-startIndex)), res)
		}
	}

	if res == big {
		return -1
	}
	return res
}
