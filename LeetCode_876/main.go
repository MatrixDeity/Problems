/**
  LeetCode_876
  https://leetcode.com/problems/middle-of-the-linked-list/
  MatrixDeity, 2022.
*/

package leetcode876

type ListNode struct {
	Val  int
	Next *ListNode
}

func middleNode(head *ListNode) *ListNode {
	if head.Next == nil {
		return head
	}

	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	return slow
}
