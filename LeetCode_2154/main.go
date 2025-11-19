package leetcode2154

/**
  LeetCode_2154
  https://leetcode.com/problems/keep-multiplying-found-values-by-two/
  MatrixDeity, 2025.
*/

func findFinalValue(nums []int, original int) int {
	set := make(map[int]struct{}, len(nums))

	for _, num := range nums {
		set[num] = struct{}{}
	}

	for {
		if _, ok := set[original]; !ok {
			return original
		}
		original <<= 1
	}
}
