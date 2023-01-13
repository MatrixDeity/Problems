/**
  LeetCode_149
  https://leetcode.com/problems/max-points-on-a-line
  MatrixDeity, 2023.
*/

package leetcode149

const (
	big float64 = 1e7
)

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func maxPoints(points [][]int) int {
	res := 1

	for i := range points {
		counter := map[float64]int{}

		for j := i + 1; j < len(points); j++ {
			if points[i][0] != points[j][0] {
				slope := float64(points[j][1]-points[i][1]) / float64(points[i][0]-points[j][0])
				counter[slope]++
			} else {
				counter[big]++
			}
		}

		tmp := 0
		for _, cnt := range counter {
			tmp = max(tmp, cnt)
		}

		res = max(res, tmp+1)
	}

	return res
}
