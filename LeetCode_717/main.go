/**
  LeetCode_717
  https://leetcode.com/problems/1-bit-and-2-bit-characters/
  MatrixDeity, 2025.
*/

package leetcode717

func isOneBitCharacter(bits []int) bool {
	i := 0
	for i < len(bits) {
		if bits[i] == 1 {
			i++
		} else if i == len(bits)-1 {
			return true
		}
		i++
	}

	return false
}
