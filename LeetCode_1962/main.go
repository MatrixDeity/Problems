/**
  LeetCode_1962
  https://leetcode.com/problems/remove-stones-to-minimize-the-total/
  MatrixDeity, 2022.
*/

package leetcode1962

import "container/heap"

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

func minStoneSum(piles []int, k int) int {
	h := &IntHeap{}
	heap.Init(h)
	res := 0

	for _, pile := range piles {
		heap.Push(h, pile)
		res += pile
	}

	for i := 0; i < k; i++ {
		top := heap.Pop(h).(int)
		half := top / 2
		res -= half
		heap.Push(h, top-half)
	}

	return res
}
