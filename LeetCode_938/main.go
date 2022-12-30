/**
  LeetCode_938
  https://leetcode.com/problems/range-sum-of-bst/
  MatrixDeity, 2022.
*/

package leetcode938

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func rangeSumBST(root *TreeNode, low int, high int) int {
	if root == nil {
		return 0
	}

	if root.Val < low {
		return rangeSumBST(root.Right, low, high)
	}

	if root.Val > high {
		return rangeSumBST(root.Left, low, high)
	}

	return root.Val + rangeSumBST(root.Left, low, high) + rangeSumBST(root.Right, low, high)
}
