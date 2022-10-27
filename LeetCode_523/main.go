/**
  LeetCode_523
  https://leetcode.com/problems/continuous-subarray-sum/
  MatrixDeity, 2022.
*/

package leetcode523

func checkSubarraySum(nums []int, k int) bool {
	sumsRem := map[int]int{}
	sum := 0

	for i, num := range nums {
		sum += num
		rem := sum % k

		if rem == 0 && i > 0 {
			return true
		}

		j, ok := sumsRem[rem]
		if ok && i-j >= 2 {
			return true
		}

		if !ok {
			sumsRem[rem] = i
		}
	}

	return false
}
