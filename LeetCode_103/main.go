/**
  LeetCode_103
  https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
  MatrixDeity, 2023.
*/

package leetcode103

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func reverse(arr []int) {
	n := len(arr)
	for i := 0; i < n/2; i++ {
		arr[i], arr[n-i-1] = arr[n-i-1], arr[i]
	}
}

func zigzagLevelOrder(root *TreeNode) [][]int {
	res := [][]int{}
	queue := []*TreeNode{root}
	depth := 0

	for len(queue) > 0 {
		queueSize := len(queue)
		tmp := []int{}

		for i := 0; i < queueSize; i++ {
			node := queue[0]
			queue = queue[1:]

			if node == nil {
				continue
			}

			tmp = append(tmp, node.Val)
			queue = append(queue, node.Left)
			queue = append(queue, node.Right)
		}

		if len(tmp) == 0 {
			continue
		}

		if depth&1 == 1 {
			reverse(tmp)
		}

		res = append(res, tmp)
		depth++
	}

	return res
}
