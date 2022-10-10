/**
  LeetCode_2233
  https://leetcode.com/problems/maximum-product-after-k-increments/
  MatrixDeity, 2022.
*/

package leetcode2233

import "container/heap"

const (
	mod = 1e9 + 7
)

type IntHeap []int

func (h IntHeap) Len() int {
	return len(h)
}

func (h IntHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h IntHeap) Less(i, j int) bool {
	return h[i] < h[j]
}

func (h *IntHeap) Push(e interface{}) {
	*h = append(*h, e.(int))
}

func (h *IntHeap) Pop() interface{} {
	n := len(*h)
	res := (*h)[n-1]
	*h = (*h)[:n-1]
	return res
}

func maximumProduct(nums []int, k int) int {
	res := 1

	h := &IntHeap{}
	heap.Init(h)

	for _, num := range nums {
		heap.Push(h, num)
	}

	for i := 0; i < k; i++ {
		heap.Push(h, heap.Pop(h).(int)+1)
	}

	for h.Len() > 0 {
		res = (res * heap.Pop(h).(int)) % mod
	}

	return res
}
