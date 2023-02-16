/**
  LeetCode_2540
  https://leetcode.com/problems/minimum-common-value/
  MatrixDeity, 2023.
*/

package leetcode2540

func getCommon(nums1 []int, nums2 []int) int {
	n, m := len(nums1), len(nums2)

	for i, j := 0, 0; i < n || j < m; {
		if j == m || i < n && nums1[i] < nums2[j] {
			i++
			continue
		}

		if i == n || j < m && nums2[j] < nums1[i] {
			j++
			continue
		}

		return nums1[i]
	}

	return -1
}
