/**
  LeetCode_2363
  https://leetcode.com/problems/merge-similar-items/
  MatrixDeity, 2022.
*/

package leetcode2363

import "sort"

func mergeSimilarItems(items1 [][]int, items2 [][]int) [][]int {
	resMap := map[int]int{}
	for _, pair := range items1 {
		resMap[pair[0]] += pair[1]
	}
	for _, pair := range items2 {
		resMap[pair[0]] += pair[1]
	}
	res := make([][]int, 0, len(resMap))
	for v, w := range resMap {
		res = append(res, []int{v, w})
	}
	sort.Slice(res, func(i, j int) bool { return res[i][0] < res[j][0] })
	return res
}
