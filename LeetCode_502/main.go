/**
  LeetCode_502
  https://leetcode.com/problems/ipo/
  MatrixDeity, 2023.
*/

package leetcode502

import "container/heap"

type pair struct {
	profit  int
	capital int
}

type pairHeap struct {
	content    []pair
	comparator func(left, right pair) bool
}

func (ph *pairHeap) Swap(i, j int) {
	ph.content[i], ph.content[j] = ph.content[j], ph.content[i]
}

func (ph *pairHeap) Len() int {
	return len(ph.content)
}

func (ph *pairHeap) Less(i, j int) bool {
	return ph.comparator(ph.content[i], ph.content[j])
}

func (ph *pairHeap) Push(value interface{}) {
	ph.content = append(ph.content, value.(pair))
}

func (ph *pairHeap) Pop() interface{} {
	top := ph.content[ph.Len()-1]
	ph.content = ph.content[:ph.Len()-1]
	return top
}

func (ph *pairHeap) Peek() *pair {
	return &ph.content[0]
}

func findMaximizedCapital(k int, w int, profits []int, capital []int) int {
	maxHeap := &pairHeap{
		content: []pair{},
		comparator: func(left, right pair) bool {
			return left.profit > right.profit
		},
	}
	minHeap := &pairHeap{
		content: []pair{},
		comparator: func(left, right pair) bool {
			return left.capital < right.capital
		},
	}

	heap.Init(maxHeap)
	heap.Init(minHeap)

	for i := range profits {
		heap.Push(minHeap, pair{profit: profits[i], capital: capital[i]})
	}

	for i := 0; i < k; i++ {
		for minHeap.Len() > 0 && minHeap.Peek().capital <= w {
			heap.Push(maxHeap, heap.Pop(minHeap))
		}

		if maxHeap.Len() == 0 {
			break
		}

		w += heap.Pop(maxHeap).(pair).profit
	}

	return w
}
