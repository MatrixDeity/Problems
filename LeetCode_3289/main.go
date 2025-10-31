/**
  LeetCode_3289
  https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/
  MatrixDeity, 2025.
*/

package leetcode3289

func getSneakyNumbers(nums []int) []int {
	const N = 102
	counter := make([]int, N)
	res := make([]int, 0, 2)

	for _, num := range nums {
		counter[num]++
		if counter[num] == 2 {
			res = append(res, num)
		}
	}

	return res
}
