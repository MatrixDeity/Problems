/**
  LeetCode_997
  https://leetcode.com/problems/find-the-town-judge/
  MatrixDeity, 2023.
*/

package leetcode997

func findJudge(n int, trust [][]int) int {
	from := make([]int, n)
	to := make([]int, n)

	for _, pair := range trust {
		from[pair[0]-1]++
		to[pair[1]-1]++
	}

	for i := range from {
		if from[i] == 0 && to[i] == n-1 {
			return i + 1
		}
	}

	return -1
}
