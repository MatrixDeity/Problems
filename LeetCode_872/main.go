/**
  LeetCode_872
  https://leetcode.com/problems/leaf-similar-trees/
  MatrixDeity, 2022.
*/

package leetcode872

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isEqual(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i, v := range a {
		if v != b[i] {
			return false
		}
	}
	return true
}

func dfs(root *TreeNode) []int {
	res := []int{}

	var impl func(node *TreeNode)
	impl = func(node *TreeNode) {
		if node == nil {
			return
		}

		if node.Left == nil && node.Right == nil {
			res = append(res, node.Val)
		}

		impl(node.Left)
		impl(node.Right)
	}
	impl(root)

	return res
}

func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	res1 := dfs(root1)
	res2 := dfs(root2)

	return isEqual(res1, res2)
}
