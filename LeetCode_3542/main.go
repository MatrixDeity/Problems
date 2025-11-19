/**
  LeetCode_3542
  https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/
  MatrixDeity, 2025.
*/

package leetcode3542

func minOperations(nums []int) int {
	stack := make([]int, 0, len(nums))
	res := 0

	for _, num := range nums {
		for len(stack) > 0 && stack[len(stack)-1] > num {
			stack = stack[:len(stack)-1]
		}

		if num == 0 {
			continue
		}

		if len(stack) == 0 || stack[len(stack)-1] < num {
			res++
			stack = append(stack, num)
		}
	}

	return res
}
