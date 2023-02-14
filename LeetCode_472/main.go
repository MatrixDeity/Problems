/**
  LeetCode_472
  https://leetcode.com/problems/concatenated-words/
  MatrixDeity, 2023.
*/

package leetcode472

func findAllConcatenatedWordsInADict(words []string) []string {
	res := []string{}
	set := make(map[string]struct{})

	for _, word := range words {
		set[word] = struct{}{}
	}

	for _, word := range words {
		n := len(word)
		dp := make([]bool, n+1)
		dp[0] = true

		for i := 1; i <= n; i++ {
			j := 0
			if i == n {
				j = 1
			}

			for ; !dp[i] && j < i; j++ {
				_, ok := set[word[j:i]]
				dp[i] = dp[j] && ok
			}
		}

		if dp[n] {
			res = append(res, word)
		}
	}

	return res
}
