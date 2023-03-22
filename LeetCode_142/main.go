/**
  LeetCode_142
  https://leetcode.com/problems/linked-list-cycle-ii/
  MatrixDeity, 2023.
*/

package leetcode142

type ListNode struct {
	Val  int
	Next *ListNode
}

func detectCycle(head *ListNode) *ListNode {
	slow, fast := head, head

	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next

		if fast == slow {
			break
		}
	}

	if fast == nil || fast.Next == nil {
		return nil
	}

	slow = head

	for slow != fast {
		slow = slow.Next
		fast = fast.Next
	}

	return slow
}
