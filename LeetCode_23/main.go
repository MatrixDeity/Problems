/**
  LeetCode_23
  https://leetcode.com/problems/merge-k-sorted-lists/
  MatrixDeity, 2023.
*/

package leetcode23

import "container/heap"

type ListNode struct {
	Val  int
	Next *ListNode
}

type ListHeap []*ListNode

func (lh ListHeap) Len() int {
	return len(lh)
}

func (lh ListHeap) Less(i, j int) bool {
	return lh[i].Val < lh[j].Val
}

func (lh ListHeap) Swap(i, j int) {
	lh[i], lh[j] = lh[j], lh[i]
}

func (lh *ListHeap) Push(x interface{}) {
	*lh = append(*lh, x.(*ListNode))
}

func (lh *ListHeap) Pop() interface{} {
	n := len(*lh)
	x := (*lh)[n-1]
	*lh = (*lh)[0 : n-1]
	return x
}

func (lh *ListHeap) SmartPop() *ListNode {
	head := (*lh)[0]

	if head.Next == nil {
		heap.Pop(lh)
	} else {
		(*lh)[0] = head.Next
		heap.Fix(lh, 0)
	}

	return head
}

func mergeKLists(lists []*ListNode) *ListNode {
	nodesHeap := ListHeap{}
	for _, node := range lists {
		if node == nil {
			continue
		}
		nodesHeap = append(nodesHeap, node)
	}

	heap.Init(&nodesHeap)
	dummy := &ListNode{}

	ptr := dummy
	for nodesHeap.Len() > 0 {
		ptr.Next = nodesHeap.SmartPop()
		ptr = ptr.Next
	}

	return dummy.Next
}
