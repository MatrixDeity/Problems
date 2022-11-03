/**
  LeetCode_2130
  https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
  MatrixDeity, 2022.
*/

package leetcode2130

type ListNode struct {
	Val  int
	Next *ListNode
}

func split(head *ListNode) (*ListNode, *ListNode) {
	slow, fast := head, head
	var prev *ListNode

	for fast != nil && fast.Next != nil {
		prev = slow
		slow = slow.Next
		fast = fast.Next.Next
	}

	if prev != nil {
		prev.Next = nil
	}

	return head, slow
}

func reverse(head *ListNode) *ListNode {
	ptr := head
	var prev *ListNode

	for ptr != nil {
		tail := ptr.Next
		ptr.Next = prev
		prev = ptr
		ptr = tail
	}

	return prev
}

func pairSum(head *ListNode) int {
	head1, head2 := split(head)
	head2 = reverse(head2)

	res := 0
	for head1 != nil && head2 != nil {
		curr := head1.Val + head2.Val
		if curr > res {
			res = curr
		}

		head1 = head1.Next
		head2 = head2.Next
	}

	return res
}
