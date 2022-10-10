/**
  LeetCode_2379
  https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
  MatrixDeity, 2022.
*/

package leetcode2379

func minimumRecolors(blocks string, k int) int {
	i, j := 0, 0
	whiteNum, res := 0, 0

	for j < len(blocks) {
		if blocks[j] == 'W' {
			whiteNum++
		}
		j++
		if j-k > i {
			if blocks[i] == 'W' {
				whiteNum--
			}
			i++
		}
		if i == 0 || res > whiteNum {
			res = whiteNum
		}
	}
	return res
}
