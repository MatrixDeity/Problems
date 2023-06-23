/**
  LeetCode_1046
  https://leetcode.com/problems/last-stone-weight/
  MatrixDeity, 2023.
*/

package leetcode1046

import "container/heap"

type Heap []int

func (h *Heap) Push(item interface{}) {
	*h = append(*h, item.(int))
}

func (h *Heap) Pop() interface{} {
	data := *h
	res := data[len(data)-1]
	*h = data[:len(data)-1]

	return res
}

func (h Heap) Len() int {
	return len(h)
}

func (h Heap) Less(i, j int) bool {
	return h[i] > h[j]
}

func (h Heap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func lastStoneWeight(stones []int) int {
	h := make(Heap, len(stones))
	copy(h, stones)
	heap.Init(&h)

	for h.Len() > 1 {
		first := heap.Pop(&h).(int)
		second := heap.Pop(&h).(int)
		heap.Push(&h, first-second)
	}

	return heap.Pop(&h).(int)
}
