/**
  LeetCode_1026
  https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
  MatrixDeity, 2022.
*/

package leetcode1026

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func maxAncestorDiff(root *TreeNode) int {
	res := 0

	var impl func(node *TreeNode, minVal, maxVal int)
	impl = func(node *TreeNode, minVal, maxVal int) {
		if node == nil {
			return
		}

		if minVal != math.MaxInt32 && maxVal != math.MinInt32 {
			res = max(abs(node.Val-minVal), res)
			res = max(abs(node.Val-maxVal), res)
		}

		impl(node.Left, min(node.Val, minVal), max(node.Val, maxVal))
		impl(node.Right, min(node.Val, minVal), max(node.Val, maxVal))
	}

	impl(root, math.MaxInt32, math.MinInt32)

	return res
}
