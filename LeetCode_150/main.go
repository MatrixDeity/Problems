/**
  LeetCode_150
  https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
  MatrixDeity, 2022.
*/

package leetcode150

import "strconv"

func evalRPN(tokens []string) int {
	stack := make([]int, 0, len(tokens))
	operators := map[string]func(a, b int) int{
		"+": func(a, b int) int {
			return a + b
		},
		"*": func(a, b int) int {
			return a * b
		},
		"/": func(a, b int) int {
			return a / b
		},
		"-": func(a, b int) int {
			return a - b
		},
	}

	for _, token := range tokens {
		num, err := strconv.Atoi(token)
		if err != nil {
			b := stack[len(stack)-1]
			a := stack[len(stack)-2]
			stack = stack[:len(stack)-2]
			stack = append(stack, operators[token](a, b))
		} else {
			stack = append(stack, num)
		}
	}

	return stack[len(stack)-1]
}
