/**
  LeetCode_944
  https://leetcode.com/problems/delete-columns-to-make-sorted/
  MatrixDeity, 2023.
*/

package leetcode944

func minDeletionSize(strs []string) int {
	res := 0

UP:
	for i := 0; i < len(strs[0]); i++ {
		for j := 1; j < len(strs); j++ {
			if strs[j][i] < strs[j-1][i] {
				res++
				continue UP
			}
		}
	}

	return res
}
