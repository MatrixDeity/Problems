/**
  LeetCode_96
  https://leetcode.com/problems/unique-binary-search-trees/
  MatrixDeity, 2022.
*/

package leetcode96

func countCN(n float64) float64 {
	if n == 0 {
		return 1
	}
	return 2 * (2*n - 1) / (n + 1) * countCN(n-1)
}

func numTrees(n int) int {
	return int(countCN(float64(n)))
}
