/**
  LeetCode_143
  https://leetcode.com/problems/reorder-list/
  MatrixDeity, 2022.
*/

package leetcode143

type ListNode struct {
	Val  int
	Next *ListNode
}

func reorderList(head *ListNode) {
	if head.Next == nil || head.Next.Next == nil {
		return
	}

	head1, head2 := splitList(head)
	head2 = reverseList(head2)
	head = mergeLists(head1, head2)
}

func splitList(head *ListNode) (*ListNode, *ListNode) {
	slow, fast := head, head

	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	head2 := slow.Next
	slow.Next = nil

	return head, head2
}

func reverseList(head *ListNode) *ListNode {
	var prev, curr *ListNode = nil, head

	for curr != nil {
		tail := curr.Next
		curr.Next = prev
		prev = curr
		curr = tail
	}

	return prev
}

func mergeLists(head1, head2 *ListNode) *ListNode {
	ptr1, ptr2 := head1, head2

	for ptr2 != nil {
		tail := ptr2.Next
		ptr2.Next = ptr1.Next
		ptr1.Next = ptr2
		ptr2 = tail
		ptr1 = ptr1.Next.Next
	}

	return head1
}
