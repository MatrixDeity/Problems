/**
  LeetCode_222
  https://leetcode.com/problems/count-complete-tree-nodes/
  MatrixDeity, 2022.
*/

package leetcode222

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func calcHeight(root *TreeNode, isLeft bool) int {
	cnt := 0

	for root != nil {
		if isLeft {
			root = root.Left
		} else {
			root = root.Right
		}
		cnt++
	}

	return cnt
}

func countNodes(root *TreeNode) int {
	l := calcHeight(root, true)
	r := calcHeight(root, false)

	if r == l {
		return int(math.Pow(2, float64(l))) - 1
	}

	return countNodes(root.Left) + countNodes(root.Right) + 1
}
