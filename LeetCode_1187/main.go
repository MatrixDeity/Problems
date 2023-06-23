/**
  LeetCode_1187
  https://leetcode.com/problems/make-array-strictly-increasing/
  MatrixDeity, 2023.
*/

package leetcode1187

import (
	"fmt"
	"math"
	"sort"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func binsearch(arr []int, prev int) int {
	i, j := 0, len(arr)-1

	for i <= j {
		m := i + (j-i)/2

		if arr[m] <= prev {
			i = m + 1
		} else {
			j = m - 1
		}
	}

	return i
}

func makeArrayIncreasing(arr1 []int, arr2 []int) int {
	sort.Ints(arr2)

	dp := make(map[string]int)

	var impl func(i, prev int) int
	impl = func(i, prev int) int {
		if i == len(arr1) {
			return 0
		}

		key := fmt.Sprintf("%d/%d", i, prev)
		if value, ok := dp[key]; ok {
			return value
		}

		res := math.MaxInt32
		if arr1[i] > prev {
			res = impl(i+1, arr1[i])
		}

		j := binsearch(arr2, prev)
		if j < len(arr2) {
			res = min(res, impl(i+1, arr2[j])+1)
		}

		dp[key] = res
		return res
	}

	res := impl(0, -1)
	if res == math.MaxInt32 {
		return -1
	}

	return res
}
