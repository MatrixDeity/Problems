/**
  LeetCode_953
  https://leetcode.com/problems/verifying-an-alien-dictionary/
  MatrixDeity, 2023.
*/

package leetcode953

func isAlienSorted(words []string, order string) bool {
	dict := make(map[byte]int)
	for i := range order {
		dict[order[i]] = i
	}

	isSorted := func(str1, str2 string) bool {
		n := len(str1)
		if n > len(str2) {
			n = len(str2)
		}

		for i := 0; i < n; i++ {
			if dict[str1[i]] < dict[str2[i]] {
				return true
			}

			if dict[str1[i]] > dict[str2[i]] {
				return false
			}
		}

		return len(str1) == n
	}

	for i := 0; i < len(words)-1; i++ {
		if !isSorted(words[i], words[i+1]) {
			return false
		}
	}

	return true
}
