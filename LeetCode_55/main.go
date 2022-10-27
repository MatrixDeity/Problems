/**
  LeetCode_55
  https://leetcode.com/problems/jump-game/
  MatrixDeity, 2022.
*/

package leetcode55

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func canJump(nums []int) bool {
	last := len(nums) - 1
	dp := make([]int, len(nums))
	for i := range nums {
		dp[i] = -1
	}

	var impl func(int) int
	impl = func(i int) int {
		if i == last {
			return 1
		}

		if dp[i] != -1 {
			return dp[i]
		}

		res := 0
		num := nums[i]
		end := min(last, i+num)
		for j := i + 1; j <= end; j++ {
			if impl(j) == 1 {
				res = 1
				break
			}
		}

		dp[i] = int(res)
		return res
	}

	return impl(0) == 1
}
