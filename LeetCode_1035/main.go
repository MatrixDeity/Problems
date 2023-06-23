/**
  LeetCode_1035
  https://leetcode.com/problems/uncrossed-lines/
  MatrixDeity, 2023.
*/

package leetcode1035

type Point struct {
	x, y int
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func maxUncrossedLines(nums1 []int, nums2 []int) int {
	dp := map[Point]int{}

	var impl func(pt Point) int
	impl = func(pt Point) int {
		if val, ok := dp[pt]; ok {
			return val
		}

		for i := pt.x + 1; i < len(nums1); i++ {
			for j := pt.y + 1; j < len(nums2); j++ {
				if nums1[i] == nums2[j] {
					dp[pt] = max(dp[pt], 1)
					dp[pt] = max(dp[pt], impl(Point{i, j})+1)
				}
			}
		}

		return dp[pt]
	}

	return impl(Point{-1, -1})
}
