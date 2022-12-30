/**
  LeetCode_2389
  https://leetcode.com/problems/longest-subsequence-with-limited-sum/
  MatrixDeity, 2022.
*/

package leetcode2389

import "sort"

func answerQueries(nums []int, queries []int) []int {
	n, m := len(nums), len(queries)
	res := make([]int, m)

	sort.Ints(nums)
	for i := 1; i < n; i++ {
		nums[i] += nums[i-1]
	}

	for i := 0; i < m; i++ {
		res[i] = sort.Search(len(nums), func(j int) bool { return nums[j] > queries[i] })
	}

	return res
}
