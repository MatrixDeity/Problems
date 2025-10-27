/**
  LeetCode_1799
  https://leetcode.com/problems/maximize-score-after-n-operations/
  MatrixDeity, 2023.
*/

package leetcode1799

func gcd(a, b int) int {
	if b == 0 {
		return a
	}

	return gcd(b, a%b)
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func maxScore(nums []int) int {
	dp := make([]int, 1<<len(nums))
	for i := 0; i < len(dp); i++ {
		dp[i] = -1
	}

	var impl func(mask, pairsPicked int) int
	impl = func(mask, pairs int) int {
		if 2*pairs == len(nums) {
			return 0
		}

		if dp[mask] == -1 {
			maxScore := 0

			for i := 0; i < len(nums); i++ {
				for j := i + 1; j < len(nums); j++ {
					if ((mask>>i)&1) == 1 || ((mask>>j)&1) == 1 {
						continue
					}

					newMask := mask | (1 << i) | (1 << j)
					currScore := (pairs + 1) * gcd(nums[i], nums[j])
					moreScore := impl(newMask, pairs+1)

					maxScore = max(currScore+moreScore, maxScore)
				}
			}

			dp[mask] = maxScore
		}

		return dp[mask]
	}

	return impl(0, 0)
}
