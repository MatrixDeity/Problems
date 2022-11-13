/**
  LeetCode_2131
  https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
  MatrixDeity, 2022.
*/

package leetcode2131

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func reverse(str string) string {
	tmp := []rune(str)
	tmp[0], tmp[1] = tmp[1], tmp[0]
	return string(tmp)
}

func longestPalindrome(words []string) int {
	halfRes := 0
	hasOdd := false
	counter := map[string]int{}

	for _, word := range words {
		counter[word]++
	}

	for str, count := range counter {
		revStr := reverse(str)
		if str == revStr {
			halfRes += count
			if count%2 == 1 {
				hasOdd = true
				halfRes--
			}
		} else {
			if revCount, ok := counter[revStr]; ok {
				halfRes += min(counter[str], revCount)
			}
		}
	}

	if hasOdd {
		halfRes++
	}

	return 2 * halfRes
}
