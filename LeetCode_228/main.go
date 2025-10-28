/**
  LeetCode_228
  https://leetcode.com/problems/summary-ranges/
  MatrixDeity, 2023.
*/

package leetcode228

import "fmt"

func summaryRanges(nums []int) []string {
	n := len(nums)
	res := make([]string, 0, n)

	for i := 0; i < n; {
		a := nums[i]
		b := a
		j := i + 1

		for ; j < n; j++ {
			if nums[j]-1 != nums[j-1] {
				break
			}

			b = nums[j]
		}

		if a == b {
			res = append(res, fmt.Sprintf("%d", a))
		} else {
			res = append(res, fmt.Sprintf("%d->%d", a, b))
		}

		i = j
	}

	return res
}
