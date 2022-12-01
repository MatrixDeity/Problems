/**
  LeetCode_224
  https://leetcode.com/problems/basic-calculator/
  MatrixDeity, 2022.
*/

package leetcode224

func calculate(s string) int {
	stack := make([]int, 0, len(s))
	number, sign := 0, 1
	currSum := 0

	for _, char := range s {
		if char >= '0' && char <= '9' {
			number = 10*number + int(char-'0')
		} else if char == '+' || char == '-' {
			currSum += sign * number
			number = 0
			sign = 1
			if char == '-' {
				sign = -1
			}
		} else if char == '(' {
			stack = append(stack, currSum, sign)
			currSum, sign = 0, 1
		} else if char == ')' {
			currSum += sign * number
			last, prelast := stack[len(stack)-1], stack[len(stack)-2]
			currSum = currSum*last + prelast
			number, sign = 0, 1
			stack = stack[:len(stack)-2]
		}
	}

	return currSum + sign*number
}
