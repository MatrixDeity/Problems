/**
  LeetCode_2256
  https://leetcode.com/problems/minimum-average-difference/
  MatrixDeity, 2022.
*/

package leetcode2256

func abs(num int64) int64 {
	if num < 0 {
		return -num
	}
	return num
}

func minimumAverageDifference(nums []int) int {
	n := len(nums)
	leftSum, rightSum := int64(0), int64(0)

	for i := range nums {
		rightSum += int64(nums[i])
	}

	res, resDiff := 0, int64(rightSum)
	for i := 0; i < n; i++ {
		leftSum += int64(nums[i])
		rightSum -= int64(nums[i])

		lAvg := leftSum / int64(i+1)
		rAvg := int64(0)
		if rightSum > 0 {
			rAvg = rightSum / int64(n-i-1)
		}

		diff := abs(rAvg - lAvg)
		if diff < resDiff {
			resDiff = diff
			res = i
		}
	}

	return res
}
