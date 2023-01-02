/**
  LeetCode_1834
  https://leetcode.com/problems/single-threaded-cpu/
  MatrixDeity, 2022.
*/

package leetcode1834

import (
	"container/heap"
	"sort"
)

type IntHeap [][]int

func (h IntHeap) Len() int {
	return len(h)
}

func (h IntHeap) Less(i, j int) bool {
	if h[i][1] == h[j][1] {
		return h[i][2] < h[j][2]
	}
	return h[i][1] < h[j][1]
}

func (h IntHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.([]int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func getOrder(tasks [][]int) []int {
	for i := 0; i < len(tasks); i++ {
		tasks[i] = append(tasks[i], i)
	}

	sort.Slice(tasks, func(i, j int) bool {
		return tasks[i][0] < tasks[j][0]
	})

	time, idx := 0, 0
	queue := &IntHeap{}
	order := []int{}

	for queue.Len() > 0 || idx < len(tasks) {
		for ; idx < len(tasks) && tasks[idx][0] <= time; idx++ {
			heap.Push(queue, tasks[idx])
		}

		if queue.Len() > 0 {
			curr := heap.Pop(queue).([]int)
			time += curr[1]
			order = append(order, curr[2])
		} else if idx < len(tasks) {
			time = tasks[idx][0]
		}
	}

	return order
}
