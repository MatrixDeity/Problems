/**
  LeetCode_974
  https://leetcode.com/problems/subarray-sums-divisible-by-k/
  MatrixDeity, 2023.
*/

package leetcode974

func subarraysDivByK(nums []int, k int) int {
	counter := map[int]int{}
	res, sum := 0, 0

	counter[0]++

	for _, num := range nums {
		sum += num
		mod := (sum%k + k) % k

		if val, ok := counter[mod]; ok {
			res += val
		}

		counter[mod]++
	}

	return res
}
