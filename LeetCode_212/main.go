/**
  LeetCode_212
  https://leetcode.com/problems/word-search-ii/
  MatrixDeity, 2022.
*/

package leetcode212

type Node struct {
	children [26]*Node
	value    string
}

func makeTrie(words []string) *Node {
	root := &Node{}

	for _, word := range words {
		curr := root
		for i := range word {
			idx := word[i] - 'a'
			if curr.children[idx] == nil {
				curr.children[idx] = &Node{}
			}
			curr = curr.children[idx]
		}
		curr.value = word
	}

	return root
}

func findWords(board [][]byte, words []string) []string {
	n := len(board)
	m := len(board[0])
	uniqRes := map[string]struct{}{}

	root := makeTrie(words)
	var impl func(i, j int, node *Node)
	impl = func(i, j int, node *Node) {
		if i < 0 || j < 0 || i >= n || j >= m {
			return
		}

		if board[i][j] < 'a' {
			return
		}

		idx := board[i][j] - 'a'
		if node.children[idx] == nil {
			return
		}

		child := node.children[idx]
		if len(child.value) > 0 {
			uniqRes[child.value] = struct{}{}
		}

		board[i][j] = '.'
		impl(i+1, j, child)
		impl(i, j+1, child)
		impl(i-1, j, child)
		impl(i, j-1, child)
		board[i][j] = idx + 'a'
	}

	for i := range board {
		for j := range board[i] {
			impl(i, j, root)
		}
	}

	res := make([]string, 0, len(uniqRes))
	for str := range uniqRes {
		res = append(res, str)
	}
	return res
}
