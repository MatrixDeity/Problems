/**
  LeetCode_907
  https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
  MatrixDeity, 2022.
*/

package leetcode1339

const (
	MOD int64 = 1e9 + 7
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func calcSum(node *TreeNode) int64 {
	if node == nil {
		return 0
	}

	return calcSum(node.Left) + calcSum(node.Right) + int64(node.Val)
}

func max(a, b int64) int64 {
	if a < b {
		return b
	}
	return a
}

func maxProduct(root *TreeNode) int {
	res := int64(0)
	fullSum := calcSum(root)

	var impl func(node *TreeNode) int64
	impl = func(node *TreeNode) int64 {
		if node == nil {
			return 0
		}

		leftSum := impl(node.Left)
		rightSum := impl(node.Right)
		leftProd := leftSum * (fullSum - leftSum)
		rightProd := rightSum * (fullSum - rightSum)
		res = max(max(leftProd, rightProd), res)

		return rightSum + leftSum + int64(node.Val)
	}

	impl(root)

	return int(res % MOD)
}
