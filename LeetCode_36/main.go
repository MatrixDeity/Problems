/**
  LeetCode_36
  https://leetcode.com/problems/valid-sudoku/
  MatrixDeity, 2022.
*/

package leetcode36

type position struct {
	x, y int
}

func isValidSudoku(board [][]byte) bool {
	rows := [9]map[byte]struct{}{}
	cols := [9]map[byte]struct{}{}
	sect := map[position]map[byte]struct{}{}

	for i := range board {
		for j := range board[i] {
			num := board[i][j]

			if num == '.' {
				continue
			}

			if rows[i] == nil {
				rows[i] = make(map[byte]struct{})
			}
			if _, ok := rows[i][num]; ok {
				return false
			}

			if cols[j] == nil {
				cols[j] = make(map[byte]struct{})
			}
			if _, ok := cols[j][num]; ok {
				return false
			}

			if sect[position{i / 3, j / 3}] == nil {
				sect[position{i / 3, j / 3}] = make(map[byte]struct{})
			}
			if _, ok := sect[position{i / 3, j / 3}][num]; ok {
				return false
			}

			rows[i][num] = struct{}{}
			cols[j][num] = struct{}{}
			sect[position{i / 3, j / 3}][num] = struct{}{}
		}
	}

	return true
}
