/**
  LeetCode_1721
  https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
  MatrixDeity, 2023.
*/

package leetcode1721

type ListNode struct {
	Val  int
	Next *ListNode
}

func swapNodes(head *ListNode, k int) *ListNode {
	newHead := ListNode{}
	newHead.Next = head

	ptr := &newHead
	for i := 1; i < k; i++ {
		ptr = ptr.Next
	}

	ptr1 := ptr
	ptr2 := &newHead
	for ptr.Next.Next != nil {
		ptr = ptr.Next
		ptr2 = ptr2.Next
	}

	node1, node2 := ptr1.Next, ptr2.Next
	if node1.Next == node2 {
		ptr1.Next, ptr2.Next, node1.Next, node2.Next = node2, node1, node2.Next, node1
	} else if node2.Next == node1 {
		ptr1.Next, ptr2.Next, node1.Next, node2.Next = node2, node1, node2, node1.Next
	} else if node1 == node2 {
		// do nothing
	} else {
		ptr1.Next, ptr2.Next, node1.Next, node2.Next = node2, node1, node2.Next, node1.Next
	}

	return newHead.Next
}
