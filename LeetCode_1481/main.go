/**
  LeetCode_1481
  https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
  MatrixDeity, 2022.
*/

package leetcode1481

import "sort"

func findLeastNumOfUniqueInts(arr []int, k int) int {
	counter := map[int]int{}
	for _, num := range arr {
		counter[num]++
	}
	uniq := make([]int, 0, len(counter))
	for _, val := range counter {
		uniq = append(uniq, val)
	}

	sort.Slice(uniq, func(i, j int) bool { return uniq[i] < uniq[j] })

	res := len(uniq)
	for _, cnt := range uniq {
		k -= cnt
		if k >= 0 {
			res--
		} else {
			break
		}
	}

	return res
}
