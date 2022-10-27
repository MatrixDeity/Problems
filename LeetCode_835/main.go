/**
  LeetCode_835
  https://leetcode.com/problems/image-overlap/
  MatrixDeity, 2022.
*/

package leetcode835

type point struct {
	x, y int
}

func largestOverlap(img1 [][]int, img2 [][]int) int {
	counter := map[point]int{}
	res := 0

	for i1 := range img1 {
		for j1 := range img1[i1] {
			if img1[i1][j1] == 0 {
				continue
			}

			for i2 := range img2 {
				for j2 := range img2[i2] {
					if img2[i2][j2] == 0 {
						continue
					}

					p := point{i2 - i1, j2 - j1}
					counter[p]++
					cur := counter[p]
					if cur > res {
						res = cur
					}
				}
			}
		}
	}

	return res
}
