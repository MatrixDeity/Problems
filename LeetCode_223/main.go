/**
  LeetCode_223
  https://leetcode.com/problems/rectangle-area/
  MatrixDeity, 2022.
*/

package leetcode223

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2 int) int {
	res := abs(ax1-ax2)*abs(ay1-ay2) + abs(bx1-bx2)*abs(by1-by2)

	x1 := max(ax1, bx1)
	y1 := max(ay1, by1)
	x2 := min(ax2, bx2)
	y2 := min(ay2, by2)

	if x2 > x1 && y2 > y1 {
		res -= abs(x1-x2) * abs(y1-y2)
	}

	return res
}
