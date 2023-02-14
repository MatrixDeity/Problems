/**
  LeetCode_491
  https://leetcode.com/problems/non-decreasing-subsequences/
  MatrixDeity, 2023.
*/

package leetcode491

func findSubsequences(nums []int) [][]int {
	res := [][]int{}
	n := len(nums)

	var impl func(i int, curr []int)
	impl = func(i int, curr []int) {
		m := len(curr)
		if i == n {
			if m > 1 {
				newCurr := make([]int, m)
				copy(newCurr, curr)
				res = append(res, newCurr)
			}
			return
		}

		if m == 0 || curr[m-1] <= nums[i] {
			impl(i+1, append(curr, nums[i]))
		}

		if m > 0 && curr[m-1] == nums[i] {
			return
		}

		impl(i+1, curr)
	}

	impl(0, make([]int, 0, n))

	return res
}
