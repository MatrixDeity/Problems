/**
  LeetCode_2352
  https://leetcode.com/problems/equal-row-and-column-pairs/
  MatrixDeity, 2023.
*/

package leetcode2352

type Node struct {
	data  map[int]*Node
	count int
}

func newNode() *Node {
	return &Node{
		data: make(map[int]*Node),
	}
}

func (n *Node) insert(row []int) {
	curr := n

	for _, num := range row {
		node := curr.data[num]

		if node == nil {
			node = newNode()
			curr.data[num] = node
		}

		curr = node
	}

	curr.count++
}

func (n *Node) find(grid [][]int, col int) int {
	l := len(grid[0])
	curr := n

	for i := 0; i < l; i++ {
		num := grid[i][col]

		if _, ok := curr.data[num]; !ok {
			return 0
		}

		curr = curr.data[num]
	}

	return curr.count
}

func equalPairs(grid [][]int) int {
	trie := newNode()
	res := 0

	for _, row := range grid {
		trie.insert(row)
	}

	for i := 0; i < len(grid[0]); i++ {
		res += trie.find(grid, i)
	}

	return res
}
