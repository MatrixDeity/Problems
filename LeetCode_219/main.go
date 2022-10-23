/**
  LeetCode_219
  https://leetcode.com/problems/contains-duplicate-ii/
  MatrixDeity, 2022.
*/

package leetcode219

func containsNearbyDuplicate(nums []int, k int) bool {
	mp := map[int]int{}

	for i, num := range nums {
		if j, ok := mp[num]; ok {
			if i-j <= k {
				return true
			}
		}
		mp[num] = i
	}

	return false
}
