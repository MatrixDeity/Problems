/**
  LeetCode_129
  https://leetcode.com/problems/sum-root-to-leaf-numbers/
  MatrixDeity, 2023.
*/

package leetcode129

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sumNumbers(root *TreeNode) int {
	res := 0

	var impl func(node *TreeNode, currNum int)
	impl = func(node *TreeNode, currNum int) {
		if node == nil {
			return
		}

		currNum *= 10
		currNum += node.Val

		if node.Left == nil && node.Right == nil {
			res += currNum
		}

		impl(node.Left, currNum)
		impl(node.Right, currNum)
	}

	impl(root, 0)

	return res
}
