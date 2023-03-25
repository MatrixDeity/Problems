/**
  LeetCode_2348
  https://leetcode.com/problems/number-of-zero-filled-subarrays/
  MatrixDeity, 2023.
*/

package leetcode2348

func zeroFilledSubarray(nums []int) int64 {
	n := len(nums)
	count := 0
	res := int64(0)

	for i := 0; i <= n; i++ {
		if i < n && nums[i] == 0 {
			count++
		} else if count > 0 {
			res += int64(count * (count + 1) / 2)
			count = 0
		}
	}

	return res
}
