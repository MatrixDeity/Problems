/**
  LeetCode_1155
  https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
  MatrixDeity, 2022.
*/

package leetcode1155

const (
	MOD = 1_000_000_007
)

func numRollsToTarget(n int, k int, target int) int {
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, target+1)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}

	var impl func(int, int) int
	impl = func(currN, currTarget int) int {
		if currN == 0 && currTarget == 0 {
			return 1
		}
		if currTarget < 0 || currN == 0 {
			return 0
		}
		if dp[currN][currTarget] != -1 {
			return dp[currN][currTarget]
		}

		count := 0
		for i := 1; i <= k; i++ {
			count += impl(currN-1, currTarget-i) % MOD
			count %= MOD
		}
		dp[currN][currTarget] = count
		return count
	}

	return impl(n, target)
}
