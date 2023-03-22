/**
  LeetCode_109
  https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
  MatrixDeity, 2023.
*/

package leetcode109

type ListNode struct {
	Val  int
	Next *ListNode
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sortedListToBST(head *ListNode) *TreeNode {
	if head == nil {
		return nil
	}

	mid := findMiddle(head)
	root := &TreeNode{Val: mid.Val}
	if mid == head {
		return root
	}

	root.Left = sortedListToBST(head)
	root.Right = sortedListToBST(mid.Next)

	return root
}

func findMiddle(head *ListNode) *ListNode {
	var prev *ListNode = nil
	slow, fast := head, head

	for fast != nil && fast.Next != nil {
		prev = slow
		slow = slow.Next
		fast = fast.Next.Next
	}

	if prev != nil {
		prev.Next = nil
	}

	return slow
}
