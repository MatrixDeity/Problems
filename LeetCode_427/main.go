/**
  LeetCode_427
  https://leetcode.com/problems/construct-quad-tree/
  MatrixDeity, 2023.
*/

package leetcode427

type Node struct {
	Val         bool
	IsLeaf      bool
	TopLeft     *Node
	TopRight    *Node
	BottomLeft  *Node
	BottomRight *Node
}

func construct(grid [][]int) *Node {
	var impl func(i, j, n int) *Node
	impl = func(i, j, n int) *Node {
		if n == 1 {
			return &Node{
				Val:    grid[i][j] == 1,
				IsLeaf: true,
			}
		}

		res := &Node{
			TopLeft:     impl(i, j, n/2),
			TopRight:    impl(i, j+n/2, n/2),
			BottomLeft:  impl(i+n/2, j, n/2),
			BottomRight: impl(i+n/2, j+n/2, n/2),
		}

		if res.TopLeft.IsLeaf &&
			res.TopRight.IsLeaf &&
			res.BottomLeft.IsLeaf &&
			res.BottomRight.IsLeaf &&
			res.TopLeft.Val == res.TopRight.Val &&
			res.TopLeft.Val == res.BottomLeft.Val &&
			res.TopLeft.Val == res.BottomRight.Val {

			res.Val = res.TopLeft.Val
			res.IsLeaf = true
			res.TopLeft = nil
			res.TopRight = nil
			res.BottomLeft = nil
			res.BottomRight = nil
		}

		return res
	}

	return impl(0, 0, len(grid))
}
