/**
  LeetCode_530
  https://leetcode.com/problems/minimum-absolute-difference-in-bst/
  MatrixDeity, 2023.
*/

package leetcode530

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func getMinimumDifference(root *TreeNode) int {
	res := math.MaxInt32
	prev := math.MinInt32

	var impl func(node *TreeNode, prev *int)
	impl = func(node *TreeNode, prev *int) {
		if node == nil {
			return
		}

		impl(node.Left, prev)

		if *prev != math.MinInt32 {
			res = min(node.Val-*prev, res)
		}
		*prev = node.Val

		impl(node.Right, prev)
	}

	impl(root, &prev)

	return res
}
