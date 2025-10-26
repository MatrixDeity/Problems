/**
  LeetCode_1498
  https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
  MatrixDeity, 2023.
*/

package leetcode1498

import (
	"sort"
)

const (
	mod int = 1e9 + 7
)

func numSubseq(nums []int, target int) int {
	sort.Ints(nums)

	n := len(nums)
	res := 0
	exps := make([]int, n+1)
	exps[1] = 1

	for i := 2; i <= n; i++ {
		exps[i] = (2 * exps[i-1]) % mod
	}

	i, j := 0, n-1
	for i <= j {
		if nums[i]+nums[j] <= target {
			res = (res + exps[j-i+1]) % mod
			i++
		} else {
			j--
		}
	}

	return res
}
