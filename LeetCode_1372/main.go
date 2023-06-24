/**
  LeetCode_1372
  https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
  MatrixDeity, 2023.
*/

package leetcode1372

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

func longestZigZag(root *TreeNode) int {
	res := 0

	var impl func(node *TreeNode) (int, int)
	impl = func(node *TreeNode) (int, int) {
		if node == nil {
			return 0, 0
		}

		_, right := impl(node.Left)
		left, _ := impl(node.Right)

		res = max(max(left, right), res)

		return right + 1, left + 1
	}

	impl(root)

	return res
}
