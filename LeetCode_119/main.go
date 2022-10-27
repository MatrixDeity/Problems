/**
  LeetCode_119
  https://leetcode.com/problems/pascals-triangle-ii/
  MatrixDeity, 2022.
*/

package leetcode119

func getRow(rowIndex int) []int {
	if rowIndex == 0 {
		return []int{1}
	}

	triangle := make([][]int, rowIndex+1)
	triangle[1] = []int{1, 1}

	for i := 2; i <= rowIndex; i++ {
		row := make([]int, i+1)
		for j := 0; j <= i; j++ {
			if j == 0 || j == i {
				row[j] = 1
				continue
			}

			row[j] = triangle[i-1][j-1] + triangle[i-1][j]
		}
		triangle[i] = row
	}

	return triangle[rowIndex]
}
