/**
  LeetCode_1569
  https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
  MatrixDeity, 2023.
*/

package leetcode1569

const mod int = 1e9 + 7

func numOfWays(nums []int) int {
	binom := make([][]int, len(nums))

	for i := 0; i < len(nums); i++ {
		binom[i] = make([]int, i+1)
		binom[i][0] = 1
		binom[i][i] = 1

		for j := 1; j < i; j++ {
			binom[i][j] = (binom[i-1][j] + binom[i-1][j-1]) % mod
		}
	}

	var impl func(nums []int) int
	impl = func(nums []int) int {
		n := len(nums)
		if n <= 2 {
			return 1
		}

		root := nums[0]
		left, right := []int{}, []int{}
		for i := 1; i < n; i++ {
			if nums[i] < root {
				left = append(left, nums[i])
			} else {
				right = append(right, nums[i])
			}
		}
		lc := impl(left) % mod
		rc := impl(right) % mod

		return (((lc * rc) % mod) * binom[n-1][len(left)]) % mod
	}

	return impl(nums) - 1
}
