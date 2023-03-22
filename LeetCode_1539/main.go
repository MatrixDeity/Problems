/**
  LeetCode_1539
  https://leetcode.com/problems/kth-missing-positive-number/
  MatrixDeity, 2023.
*/

package leetcode1539

func findKthPositive(arr []int, k int) int {
	i, j := 0, len(arr)-1

	for i <= j {
		m := i + (j-i)/2
		if arr[m]-m-1 < k {
			i = m + 1
		} else {
			j = m - 1
		}
	}

	return i + k
}
