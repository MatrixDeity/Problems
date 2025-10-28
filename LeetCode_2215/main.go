/**
  LeetCode_2215
  https://leetcode.com/problems/find-the-difference-of-two-arrays/
  MatrixDeity, 2023.
*/

package leetcode2215

func findDifference(nums1 []int, nums2 []int) [][]int {
	n, m := len(nums1), len(nums2)
	res := make([][]int, 2)
	res[0] = make([]int, 0, n)
	res[1] = make([]int, 0, m)

	set1 := make(map[int]struct{}, n)
	set2 := make(map[int]struct{}, m)

	for _, num := range nums1 {
		set1[num] = struct{}{}
	}

	for _, num := range nums2 {
		set2[num] = struct{}{}
	}

	for _, num := range nums1 {
		if _, ok := set2[num]; !ok {
			res[0] = append(res[0], num)
			set2[num] = struct{}{}
		}
	}

	for _, num := range nums2 {
		if _, ok := set1[num]; !ok {
			res[1] = append(res[1], num)
			set1[num] = struct{}{}
		}
	}

	return res
}
