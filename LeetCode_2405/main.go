/**
  LeetCode_2405
  https://leetcode.com/problems/optimal-partition-of-string/
  MatrixDeity, 2023.
*/

package leetcode2405

func partitionString(s string) int {
	set := make(map[rune]struct{})
	res := 1

	for _, char := range s {
		if _, ok := set[char]; ok {
			set = make(map[rune]struct{})
			res++
		}

		set[char] = struct{}{}
	}

	return res
}
