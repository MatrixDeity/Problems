/**
  LeetCode_692
  https://leetcode.com/problems/top-k-frequent-words/
  MatrixDeity, 2022.
*/

package leetcode692

import "sort"

type pair struct {
	word  string
	count int
}

func topKFrequent(words []string, k int) []string {
	counter := map[string]int{}
	for _, word := range words {
		counter[word]++
	}

	pairs := make([]pair, 0, len(counter))
	for key, val := range counter {
		pairs = append(pairs, pair{key, val})
	}
	sort.Slice(pairs, func(i, j int) bool {
		if pairs[i].count > pairs[j].count {
			return true
		}
		if pairs[i].count == pairs[j].count {
			return pairs[i].word < pairs[j].word
		}
		return false
	})

	res := make([]string, k)
	for i := range res {
		res[i] = pairs[i].word
	}

	return res
}
