/**
  LeetCode_2435
  https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/
  MatrixDeity, 2025.
*/

package leetcode2435

func numberOfPaths(grid [][]int, k int) int {
	const mod int = 1e9 + 7
	m := len(grid)
	n := len(grid[0])

	dp := make([][][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([][]int, n)
		for j := 0; j < n; j++ {
			dp[i][j] = make([]int, k)
		}
	}
	dp[0][0][grid[0][0]%k] = 1

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for md := 0; md < k; md++ {
				dp[i][j][md] %= mod
				if i+1 < m {
					dp[i+1][j][(md+grid[i+1][j])%k] += dp[i][j][md]
				}
				if j+1 < n {
					dp[i][j+1][(md+grid[i][j+1])%k] += dp[i][j][md]
				}
			}
		}
	}

	return dp[m-1][n-1][0]
}
