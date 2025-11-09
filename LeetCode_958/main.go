/**
  LeetCode_958
  https://leetcode.com/problems/check-completeness-of-a-binary-tree/
  MatrixDeity, 2023.
*/

package leetcode958

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isCompleteTree(root *TreeNode) bool {
	queue := []*TreeNode{root}
	isEnd := false

	for len(queue) > 0 {
		curr := queue[0]
		queue = queue[1:]

		if curr != nil {
			if isEnd {
				return false
			}

			queue = append(queue, curr.Left)
			queue = append(queue, curr.Right)
		} else {
			isEnd = true
		}
	}

	return true
}
