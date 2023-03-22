/**
  LeetCode_106
  https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
  MatrixDeity, 2023.
*/

package leetcode106

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func find(arr []int, target int) int {
	for i, elem := range arr {
		if elem == target {
			return i
		}
	}

	return -1
}

func buildTree(inorder []int, postorder []int) *TreeNode {
	if len(inorder) == 0 || len(postorder) == 0 {
		return nil
	}

	root := &TreeNode{
		Val: postorder[len(postorder)-1],
	}

	if len(postorder) < 2 {
		return root
	}

	rootIndex := find(inorder, root.Val)
	leftInorder := inorder[0:rootIndex]
	rightInorder := inorder[rootIndex+1:]

	leftPostorder := postorder[0:len(leftInorder)]
	rightPostorder := postorder[(len(postorder) - len(rightInorder) - 1) : len(postorder)-1]

	root.Left = buildTree(leftInorder, leftPostorder)
	root.Right = buildTree(rightInorder, rightPostorder)

	return root
}
