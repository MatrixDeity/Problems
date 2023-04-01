/**
  LeetCode_1444
  https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
  MatrixDeity, 2023.
*/

package leetcode1444

import "fmt"

const (
	mod int = 1e9 + 7
)

func ways(pizza []string, k int) int {
	m, n := len(pizza), len(pizza[0])
	dp := make(map[string]int, n*m*k)
	counter := make([][]int, m+1)
	counter[m] = make([]int, n+1)

	for i := m - 1; i >= 0; i-- {
		counter[i] = make([]int, n+1)
		for j := n - 1; j >= 0; j-- {
			counter[i][j] = counter[i+1][j] + counter[i][j+1] - counter[i+1][j+1]
			if pizza[i][j] == 'A' {
				counter[i][j]++
			}
		}
	}

	var impl func(i, j, k int) int
	impl = func(i, j, k int) int {
		if k == 0 {
			if counter[i][j] > 0 {
				return 1
			}
			return 0
		}

		key := fmt.Sprintf("%d/%d/%d", i, j, k)
		if val, ok := dp[key]; ok {
			return val
		}

		res := 0
		for x := i + 1; x < m; x++ {
			if counter[i][j]-counter[x][j] > 0 {
				res = (res + impl(x, j, k-1)) % mod
			}
		}

		for y := j + 1; y < n; y++ {
			if counter[i][j]-counter[i][y] > 0 {
				res = (res + impl(i, y, k-1)) % mod
			}
		}

		dp[key] = res
		return res
	}

	return impl(0, 0, k-1)
}
