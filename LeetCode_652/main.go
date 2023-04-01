/**
  LeetCode_652
  https://leetcode.com/problems/find-duplicate-subtrees/
  MatrixDeity, 2023.
*/

package leetcode652

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findDuplicateSubtrees(root *TreeNode) []*TreeNode {
	idsByStr := make(map[string]int)
	counter := make(map[int]int)
	curID := 1
	res := []*TreeNode{}

	var impl func(root *TreeNode) int
	impl = func(root *TreeNode) int {
		if root == nil {
			return 0
		}

		leftID := impl(root.Left)
		rightID := impl(root.Right)
		curStr := fmt.Sprintf("%d/%d/%d", leftID, root.Val, rightID)

		id := curID
		if v, ok := idsByStr[curStr]; ok {
			id = v
		}

		if id == curID {
			curID++
		}

		idsByStr[curStr] = id
		counter[id]++

		if counter[id] == 2 {
			res = append(res, root)
		}

		return id
	}

	impl(root)

	return res
}
