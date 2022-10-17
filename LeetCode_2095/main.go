/**
  LeetCode_2095
  https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
  MatrixDeity, 2022.
*/

package leetcode2095

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteMiddle(head *ListNode) *ListNode {
	if head.Next == nil {
		return nil
	}

	var prev, slow, fast *ListNode = nil, head, head
	for fast != nil && fast.Next != nil {
		prev = slow
		slow = slow.Next
		fast = fast.Next.Next
	}

	prev.Next = prev.Next.Next

	return head
}
