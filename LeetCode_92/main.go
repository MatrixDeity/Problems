/**
  LeetCode_92
  https://leetcode.com/problems/reverse-linked-list-ii/
  MatrixDeity, 2022.
*/

package leetcode92

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) (*ListNode, *ListNode) {
	ptr := head
	var prev *ListNode

	for ptr != nil {
		tail := ptr.Next
		ptr.Next = prev
		prev = ptr
		ptr = tail
	}

	return prev, head
}

func reverseBetween(head *ListNode, left int, right int) *ListNode {
	prevHead := &ListNode{}
	prevHead.Next = head
	lPtr, rPtr := prevHead, prevHead

	left--
	for left > 0 {
		lPtr = lPtr.Next
		left--
	}

	for right > 0 {
		rPtr = rPtr.Next
		right--
	}
	tail := rPtr.Next
	rPtr.Next = nil

	newHead, last := reverseList(lPtr.Next)
	lPtr.Next = newHead
	last.Next = tail

	return prevHead.Next
}
