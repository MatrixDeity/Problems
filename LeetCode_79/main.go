/**
  LeetCode_79
  https://leetcode.com/problems/word-search/
  MatrixDeity, 2022.
*/

package leetcode79

func exist(board [][]byte, word string) bool {
	n := len(board)
	m := len(board[0])

	var impl func(i, j, idx int) bool
	impl = func(i, j, idx int) bool {
		if idx == len(word) {
			return true
		}

		if i < 0 || j < 0 || i >= n || j >= m {
			return false
		}

		char := board[i][j]
		if word[idx] != char {
			return false
		}

		board[i][j] = '.'
		res := false
		res = res || impl(i+1, j, idx+1)
		res = res || impl(i, j+1, idx+1)
		res = res || impl(i-1, j, idx+1)
		res = res || impl(i, j-1, idx+1)
		board[i][j] = char

		return res
	}

	res := false
	for i := range board {
		for j := range board[i] {
			res = res || impl(i, j, 0)
		}
	}

	return res
}
