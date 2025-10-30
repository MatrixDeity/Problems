/**
  LeetCode_703
  https://leetcode.com/problems/kth-largest-element-in-a-stream/
  MatrixDeity, 2023.
*/

package leetcode703

import "container/heap"

type MinHeap []int

func (h MinHeap) Len() int {
	return len(h)
}

func (h MinHeap) Less(i, j int) bool {
	return h[i] < h[j]
}

func (h MinHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *MinHeap) Push(i interface{}) {
	*h = append(*h, i.(int))
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := h.Len()
	res := old[n-1]
	*h = old[0 : n-1]
	return res
}

type KthLargest struct {
	Size int
	Heap *MinHeap
}

func Constructor(k int, nums []int) KthLargest {
	h := &MinHeap{}
	heap.Init(h)

	res := KthLargest{
		Size: k,
		Heap: h,
	}

	for _, num := range nums {
		res.Add(num)
	}

	return res
}

func (this *KthLargest) Add(val int) int {
	heap.Push(this.Heap, val)

	if this.Heap.Len() > this.Size {
		heap.Pop(this.Heap)
	}

	return (*this.Heap)[0]
}
