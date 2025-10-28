/**
  LeetCode_2448
  https://leetcode.com/problems/minimum-cost-to-make-array-equal/
  MatrixDeity, 2023.
*/

package leetcode2448

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a < b {
		return b
	}

	return a
}

func minCost(nums []int, cost []int) int64 {
	arr := [][2]int{}
	for i, num := range nums {
		arr = append(arr, [2]int{num, cost[i]})
	}

	i, j := 0, 0
	for _, num := range nums {
		i = min(i, num)
		j = max(j, num)
	}

	impl := func(target int) int64 {
		res := int64(0)

		for _, item := range arr {
			num, cost := item[0], item[1]
			res += int64(abs((num - target)) * cost)
		}

		return res
	}

	for i < j {
		m := i + (j-i)/2
		cost1, cost2 := impl(m), impl(m+1)

		if cost1 < cost2 {
			j = m
		} else {
			i = m + 1
		}
	}

	return impl(i)
}
