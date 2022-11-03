/**
  LeetCode_443
  https://leetcode.com/problems/minimum-genetic-mutation/
  MatrixDeity, 2022.
*/

package leetcode433

const (
	bigInt int = 999999
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func countDiff(a, b string) int {
	cnt := 0
	for i := range a {
		if a[i] != b[i] {
			cnt++
		}
	}
	return cnt
}

func minMutation(start string, end string, bank []string) int {
	dp := map[string]int{}
	visited := map[string]struct{}{}

	var impl func(string) int
	impl = func(curr string) int {
		if curr == end {
			return 0
		}

		if _, ok := visited[curr]; ok {
			return bigInt
		}

		if val, ok := dp[curr]; ok {
			return val
		}

		res := bigInt
		visited[curr] = struct{}{}
		for _, str := range bank {
			diff := countDiff(curr, str)
			if diff == 1 {
				res = min(res, impl(str)+1)
			}
		}
		delete(visited, curr)

		return res
	}

	res := impl(start)
	if res > len(bank) {
		return -1
	}
	return res
}
