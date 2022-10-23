/**
  LeetCode_12
  https://leetcode.com/problems/integer-to-roman/
  MatrixDeity, 2022.
*/

package leetcode12

import "strings"

type pair struct {
	arab int
	rom  string
}

func intToRoman(num int) string {
	pattern := []pair{
		{1000, "M"},
		{900, "CM"},
		{500, "D"},
		{400, "CD"},
		{100, "C"},
		{90, "XC"},
		{50, "L"},
		{40, "XL"},
		{10, "X"},
		{9, "IX"},
		{5, "V"},
		{4, "IV"},
		{1, "I"},
	}

	res := strings.Builder{}
	for _, pair := range pattern {
		for pair.arab <= num {
			num -= pair.arab
			res.WriteString(pair.rom)
		}
	}

	return res.String()
}
