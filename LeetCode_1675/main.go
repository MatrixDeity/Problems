/**
  LeetCode_1675
  https://leetcode.com/problems/minimize-deviation-in-array/
  MatrixDeity, 2023.
*/

package leetcode1675

import (
	"container/heap"
	"math"
)

type IntHeap []int

func (h IntHeap) Len() int {
	return len(h)
}

func (h IntHeap) Less(i, j int) bool {
	return h[i] > h[j]
}

func (h IntHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	x := old[len(old)-1]
	*h = old[0 : len(old)-1]
	return x
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minimumDeviation(nums []int) int {
	n := len(nums)
	res := math.MaxInt32
	minNum := math.MaxInt32
	h := make(IntHeap, 0, n)

	for i := range nums {
		if nums[i]%2 == 0 {
			h = append(h, nums[i])
		} else {
			h = append(h, nums[i]*2)
		}

		minNum = min(minNum, h[i])
	}

	heap.Init(&h)

	for {
		num := heap.Pop(&h).(int)
		res = min(res, num-minNum)

		if num%2 == 1 {
			break
		}

		num /= 2
		heap.Push(&h, num)
		minNum = min(minNum, num)
	}
	return res
}
