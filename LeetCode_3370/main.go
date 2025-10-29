/**
  LeetCode_3370
  https://leetcode.com/problems/smallest-number-with-all-set-bits/
  MatrixDeity, 2025.
*/

package leetcode3370

import "math/bits"

func smallestNumber(n int) int {
	return 1<<bits.Len(uint(n)) - 1
}
