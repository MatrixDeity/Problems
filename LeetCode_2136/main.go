/**
  LeetCode_2136
  https://leetcode.com/problems/earliest-possible-day-of-full-bloom/
  MatrixDeity, 2022.
*/

package leetcode2136

import (
	"sort"
)

type plant struct {
	plantTime, growTime int
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func earliestFullBloom(plantTime []int, growTime []int) int {
	plants := make([]plant, len(plantTime))

	for i := range plantTime {
		plants[i] = plant{plantTime: plantTime[i], growTime: growTime[i]}
	}

	sort.Slice(plants, func(i, j int) bool {
		if plants[j].growTime < plants[i].growTime {
			return true
		}
		if plants[j].growTime == plants[i].growTime {
			return plants[j].plantTime < plants[i].plantTime
		}
		return false
	})

	curr, res := 0, 0

	for i := range plants {
		curr += plants[i].plantTime
		res = max(res, curr+plants[i].growTime)
	}

	return res
}
