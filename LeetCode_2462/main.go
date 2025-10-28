/**
  LeetCode_2462
  https://leetcode.com/problems/total-cost-to-hire-k-workers/
  MatrixDeity, 2023.
*/

package leetcode2462

import "container/heap"

type MinHeap [][]int

func (h MinHeap) Len() int {
	return len(h)
}

func (h MinHeap) Less(i, j int) bool {
	if h[i][0] == h[j][0] {
		return h[i][1] < h[j][1]
	}
	return h[i][0] < h[j][0]
}

func (h MinHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.([]int))
}

func (h *MinHeap) Pop() interface{} {
	x := (*h)[len(*h)-1]
	*h = (*h)[:len(*h)-1]
	return x
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func totalCost(costs []int, k int, candidates int) int64 {
	minHeap := &MinHeap{}

	for i := 0; i < candidates; i++ {
		heap.Push(minHeap, []int{costs[i], 0})
	}

	for i := max(candidates, len(costs)-candidates); i < len(costs); i++ {
		heap.Push(minHeap, []int{costs[i], 1})
	}

	l, r := candidates, len(costs)-1-candidates
	res := 0

	for i := 0; i < k; i++ {
		candidate := heap.Pop(minHeap).([]int)
		res += candidate[0]
		idx := candidate[1]

		if l <= r {
			if idx == 0 {
				heap.Push(minHeap, []int{costs[l], 0})
				l++
			} else {
				heap.Push(minHeap, []int{costs[r], 1})
				r--
			}
		}
	}

	return int64(res)
}
