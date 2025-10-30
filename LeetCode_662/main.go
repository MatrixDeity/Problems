/**
  LeetCode_662
  https://leetcode.com/problems/maximum-width-of-binary-tree/
  MatrixDeity, 2023.
*/

package leetcode662

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Pair struct {
	node *TreeNode
	idx  int
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func widthOfBinaryTree(root *TreeNode) int {
	queue := []Pair{{root, 1}}
	res := 0

	for len(queue) > 0 {
		tmp := []Pair{}

		left := queue[0].idx
		right := queue[len(queue)-1].idx
		res = max(res, right-left+1)

		for _, pair := range queue {
			if pair.node.Left != nil {
				tmp = append(tmp, Pair{pair.node.Left, (pair.idx * 2) - 1})
			}

			if pair.node.Right != nil {
				tmp = append(tmp, Pair{pair.node.Right, pair.idx * 2})
			}
		}

		queue = tmp
	}

	return res
}
