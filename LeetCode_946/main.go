/**
  LeetCode_946
  https://leetcode.com/problems/validate-stack-sequences/
  MatrixDeity, 2023.
*/

package leetcode946

func validateStackSequences(pushed []int, popped []int) bool {
	i, j := 0, 0
	n := len(pushed)
	stack := make([]int, 0, n)

	for i < n {
		if len(stack) > 0 && stack[len(stack)-1] == popped[j] {
			stack = stack[:len(stack)-1]
			j++
		} else {
			stack = append(stack, pushed[i])
			i++
		}
	}

	for j < n {
		if len(stack) == 0 || stack[len(stack)-1] != popped[j] {
			return false
		}

		stack = stack[:len(stack)-1]
		j++
	}

	return true
}
