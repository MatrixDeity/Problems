/**
  LeetCode_587
  https://leetcode.com/problems/erect-the-fence/
  MatrixDeity, 2022.
*/

package leetcode587

import "sort"

func calcAngle(a, b, c []int) int {
	return (b[0]-a[0])*(c[1]-b[1]) - (b[1]-a[1])*(c[0]-b[0])
}

func outerTrees(trees [][]int) [][]int {
	n := len(trees)
	res := make([][]int, 0, n)

	sort.Slice(trees, func(i, j int) bool {
		return trees[i][0] < trees[j][0] || (trees[i][0] == trees[j][0] && trees[i][1] < trees[j][1])
	})

	for i := 0; i < n; i++ {
		for len(res) > 1 && calcAngle(res[len(res)-2], res[len(res)-1], trees[i]) < 0 {
			res = res[:len(res)-1]
		}
		res = append(res, trees[i])
	}

	if len(res) == n {
		return res
	}

	for i := n - 2; i >= 0; i-- {
		for len(res) > 1 && calcAngle(res[len(res)-2], res[len(res)-1], trees[i]) < 0 {
			res = res[:len(res)-1]
		}
		res = append(res, trees[i])
	}

	res = res[:len(res)-1]
	return res
}
