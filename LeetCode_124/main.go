/**
  LeetCode_124
  https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
  MatrixDeity, 2022.
*/

package leetcode124

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func maxPathSum(root *TreeNode) int {
	res := math.MinInt32

	var impl func(node *TreeNode) int
	impl = func(node *TreeNode) int {
		if node == nil {
			return 0
		}

		leftSum := max(impl(node.Left), 0)
		rightSum := max(impl(node.Right), 0)
		curr := node.Val + leftSum + rightSum

		res = max(curr, res)

		return node.Val + max(leftSum, rightSum)
	}

	impl(root)

	return res
}
