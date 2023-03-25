/**
  LeetCode_347
  https://leetcode.com/problems/top-k-frequent-elements/
  MatrixDeity, 2023.
*/

package leetcode347

import "sort"

type Pair struct {
	Val int
	Num int
}

func topKFrequent(nums []int, k int) []int {
	counter := map[int]int{}

	for _, num := range nums {
		counter[num]++
	}

	pairs := make([]Pair, 0, len(nums))
	for key, val := range counter {
		pairs = append(pairs, Pair{Val: key, Num: val})
	}

	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i].Num > pairs[j].Num
	})

	res := make([]int, 0, k)
	for _, pair := range pairs[:k] {
		res = append(res, pair.Val)
	}

	return res
}
