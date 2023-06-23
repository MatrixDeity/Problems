/**
  LeetCode_1161
  https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
  MatrixDeity, 2023.
*/

package leetcode1161

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxLevelSum(root *TreeNode) int {
	queue := []*TreeNode{root}
	res := 1
	maxSum := root.Val
	lvl := 1

	for len(queue) > 0 {
		n := len(queue)
		currSum := 0

		for i := 0; i < n; i++ {
			node := queue[i]

			currSum += node.Val

			if node.Left != nil {
				queue = append(queue, node.Left)
			}

			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}

		if currSum > maxSum {
			maxSum = currSum
			res = lvl
		}

		lvl++
		queue = queue[n:]
	}

	return res
}
