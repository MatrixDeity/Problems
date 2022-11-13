/**
  LeetCode_295
  https://leetcode.com/problems/find-median-from-data-stream/
  MatrixDeity, 2022.
*/

package leetcode295

import "container/heap"

type MyHeap struct {
	Content    []int
	Comparator func(int, int) bool
}

func (mh *MyHeap) Swap(i, j int) {
	mh.Content[i], mh.Content[j] = mh.Content[j], mh.Content[i]
}

func (mh *MyHeap) Less(left, right int) bool {
	return mh.Comparator(mh.Content[left], mh.Content[right])
}

func (mh *MyHeap) Len() int {
	return len(mh.Content)
}

func (mh *MyHeap) Push(value interface{}) {
	mh.Content = append(mh.Content, value.(int))
}

func (mh *MyHeap) Pop() interface{} {
	res := mh.Content[mh.Len()-1]
	mh.Content = mh.Content[:mh.Len()-1]
	return res
}

func (mh *MyHeap) Peek() int {
	return mh.Content[0]
}

type MedianFinder struct {
	minHeap *MyHeap
	maxHeap *MyHeap
}

func Constructor() MedianFinder {
	return MedianFinder{
		minHeap: &MyHeap{
			Comparator: func(left, right int) bool {
				return left > right
			},
		},
		maxHeap: &MyHeap{
			Comparator: func(left, right int) bool {
				return left < right
			},
		},
	}
}

func (this *MedianFinder) AddNum(num int) {
	if (this.minHeap.Len()+this.maxHeap.Len())%2 == 0 {
		heap.Push(this.minHeap, num)
		heap.Push(this.maxHeap, heap.Pop(this.minHeap))
	} else {
		heap.Push(this.maxHeap, num)
		heap.Push(this.minHeap, heap.Pop(this.maxHeap))
	}
}

func (this *MedianFinder) FindMedian() float64 {
	if (this.minHeap.Len()+this.maxHeap.Len())%2 == 0 {
		return float64(this.minHeap.Peek()+this.maxHeap.Peek()) / 2
	}
	return float64(this.maxHeap.Peek())
}
