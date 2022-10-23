/**
  LeetCode_209
  https://leetcode.com/problems/minimum-size-subarray-sum/
  MatrixDeity, 2022.
*/

package leetcode209

func minSubArrayLen(target int, nums []int) int {
	ans := len(nums) + 1
	i := 0
	currSum := 0

	for j := range nums {
		currSum += nums[j]

		for currSum >= target {
			if ans > j-i+1 {
				ans = j - i + 1
			}
			currSum -= nums[i]
			i++
		}
	}

	if ans > len(nums) {
		return 0
	}
	return ans
}
