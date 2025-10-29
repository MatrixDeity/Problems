/**
  LeetCode_2542
  https://leetcode.com/problems/maximum-subsequence-score/
  MatrixDeity, 2023.
*/

package leetcode2542

import (
	"container/heap"
	"sort"
)

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

type MinHeap [][2]int

func (h MinHeap) Len() int {
	return len(h)
}

func (h MinHeap) Less(i, j int) bool {
	return h[i][0] < h[j][0]
}

func (h MinHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.([2]int))
}

func (h *MinHeap) Pop() interface{} {
	res := (*h)[len(*h)-1]
	*h = (*h)[:len(*h)-1]

	return res
}

func maxScore(nums1 []int, nums2 []int, k int) int64 {
	arr := [][2]int{}
	for i := 0; i < len(nums1); i++ {
		arr = append(arr, [2]int{nums1[i], nums2[i]})
	}

	sort.Slice(arr, func(i, j int) bool {
		return arr[i][1] > arr[j][1]
	})

	h := &MinHeap{}
	sum := 0

	heap.Init(h)
	for i := 0; i < k; i++ {
		heap.Push(h, arr[i])
		sum += arr[i][0]
	}

	res := sum * arr[k-1][1]

	for i := k; i < len(arr); i++ {
		top := heap.Pop(h).([2]int)
		sum += arr[i][0] - top[0]

		heap.Push(h, arr[i])

		res = max(res, sum*arr[i][1])
	}

	return int64(res)
}
