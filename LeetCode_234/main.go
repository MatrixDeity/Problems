/**
  LeetCode_234
  https://leetcode.com/problems/palindrome-linked-list/
  MatrixDeity, 2022.
*/

package leetcode234

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

func isPalindrome(head *ListNode) bool {
	head1, head2 := split(head)
	head2 = reverse(head2)

	for head1 != nil && head2 != nil {
		if head1.Val != head2.Val {
			return false
		}
		head1 = head1.Next
		head2 = head2.Next
	}

	return true
}
