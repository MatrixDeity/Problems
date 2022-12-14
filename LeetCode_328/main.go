/**
  LeetCode_328
  https://leetcode.com/problems/odd-even-linked-list/
  MatrixDeity, 2022.
*/

package leetcode328

type ListNode struct {
	Val  int
	Next *ListNode
}

func oddEvenList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	head1, ptr1 := head, head
	head2, ptr2 := head.Next, head.Next
	ptr := head.Next.Next
	isOdd := true

	for ptr != nil {
		if isOdd {
			ptr1.Next = ptr
			ptr1 = ptr
		} else {
			ptr2.Next = ptr
			ptr2 = ptr
		}
		isOdd = !isOdd
		ptr = ptr.Next
	}

	ptr1.Next = head2
	ptr2.Next = nil

	return head1
}
