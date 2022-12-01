/**
  LeetCode_2225
  https://leetcode.com/problems/find-players-with-zero-or-one-losses/
  MatrixDeity, 2022.
*/

package leetcode2225

import "sort"

func findWinners(matches [][]int) [][]int {
	losers := map[int]int{}

	for _, match := range matches {
		if _, ok := losers[match[0]]; !ok {
			losers[match[0]] = 0
		}
		losers[match[1]]++
	}

	resFirst := make([]int, 0, len(losers))
	resSecond := make([]int, 0, len(losers))
	for part, loses := range losers {
		if loses == 0 {
			resFirst = append(resFirst, part)
		} else if loses == 1 {
			resSecond = append(resSecond, part)
		}
	}

	sort.Slice(resFirst, func(i, j int) bool { return resFirst[i] < resFirst[j] })
	sort.Slice(resSecond, func(i, j int) bool { return resSecond[i] < resSecond[j] })

	return [][]int{resFirst, resSecond}
}
