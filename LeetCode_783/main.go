/**
  LeetCode_783
  https://leetcode.com/problems/minimum-distance-between-bst-nodes/
  MatrixDeity, 2023.
*/

package leetcode783

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

const (
	big int = 1e6
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func minDiffInBST(root *TreeNode) int {
	res := big

	var impl func(node *TreeNode, mx int, mn int)
	impl = func(node *TreeNode, mx int, mn int) {
		if node == nil {
			return
		}

		minDiff := min(abs(mx-node.Val), abs(node.Val-mn))
		res = min(minDiff, res)
		impl(node.Left, node.Val, mn)
		impl(node.Right, mx, node.Val)
	}

	impl(root, -big, big)

	return res
}
