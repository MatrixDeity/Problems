/**
  LeetCode_1232
  https://leetcode.com/problems/check-if-it-is-a-straight-line/
  MatrixDeity, 2023.
*/

package leetcode1232

func checkStraightLine(coordinates [][]int) bool {
	x1, y1 := coordinates[0][0], coordinates[0][1]
	x2, y2 := coordinates[1][0], coordinates[1][1]

	for i := 1; i < len(coordinates); i++ {
		x, y := coordinates[i][0], coordinates[i][1]

		if (x2-x1)*(y-y2) != (y2-y1)*(x-x2) {
			return false
		}
	}

	return true
}
