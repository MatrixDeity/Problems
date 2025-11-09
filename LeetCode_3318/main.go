/**
  LeetCode_3318
  https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/
  MatrixDeity, 2025.
*/

package leetcode3318

import (
	"sort"
)

type pair struct {
	num   int
	count int
}

func findXSum(nums []int, k int, x int) []int {
	counter := make(map[int]int, len(nums))
	for i := 0; i < k; i++ {
		counter[nums[i]]++
	}

	res := []int{calcXFreq(counter, x)}
	for i := k; i < len(nums); i++ {
		counter[nums[i]]++
		counter[nums[i-k]]--

		res = append(res, calcXFreq(counter, x))
	}

	return res
}

func calcXFreq(counter map[int]int, x int) int {
	pairs := make([]pair, 0, len(counter))
	for n, c := range counter {
		pairs = append(pairs, pair{num: n, count: c})
	}

	sort.Slice(pairs, func(i, j int) bool {
		if pairs[i].count == pairs[j].count {
			return pairs[i].num > pairs[j].num
		}

		return pairs[i].count > pairs[j].count
	})

	res := 0
	l := min(x, len(pairs))

	for i := 0; i < l; i++ {
		res += pairs[i].count * pairs[i].num
	}

	return res
}
