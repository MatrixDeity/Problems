/**
  LeetCode_520
  https://leetcode.com/problems/detect-capital
  MatrixDeity, 2023.
*/

package leetcode520

import "unicode"

func detectCapitalUse(word string) bool {
	isCapitalized := true
	isTitled := true
	isLowered := true

	for i, char := range word {
		isLowered = isLowered && unicode.IsLower(char)
		isCapitalized = isCapitalized && unicode.IsUpper(char)
		isTitled = isTitled && (i == 0 && unicode.IsUpper(char) || i > 0 && unicode.IsLower(char))
	}

	return isCapitalized || isLowered || isTitled
}
