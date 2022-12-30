/**
  LeetCode_739
  https://leetcode.com/problems/daily-temperatures/description/
  MatrixDeity, 2022.
*/

package leetcode739

func dailyTemperatures(temperatures []int) []int {
	n := len(temperatures)
	stack := make([]int, 0, n)
	res := make([]int, n)

	for i := n - 1; i >= 0; i-- {
		for len(stack) > 0 && temperatures[stack[len(stack)-1]] <= temperatures[i] {
			stack = stack[:len(stack)-1]
		}

		if len(stack) > 0 {
			res[i] = stack[len(stack)-1] - i
		} else {
			res[i] = 0
		}

		stack = append(stack, i)
	}

	return res
}
