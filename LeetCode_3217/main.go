/**
  LeetCode_3217
  https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
  MatrixDeity, 2025.
*/

package leetcode3217

type ListNode struct {
	Val  int
	Next *ListNode
}

func modifiedList(nums []int, head *ListNode) *ListNode {
	set := make(map[int]struct{}, len(nums))

	for _, num := range nums {
		set[num] = struct{}{}
	}

	for head != nil {
		if _, ok := set[head.Val]; ok {
			head = head.Next
		} else {
			break
		}
	}

	prev := head
	for prev != nil && prev.Next != nil {
		if _, ok := set[prev.Next.Val]; ok {
			prev.Next = prev.Next.Next
		} else {
			prev = prev.Next
		}
	}

	return head
}
