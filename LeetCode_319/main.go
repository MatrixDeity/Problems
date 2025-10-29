/**
  LeetCode_319
  https://leetcode.com/problems/bulb-switcher/
  MatrixDeity, 2023.
*/

package leetcode319

import "math"

func bulbSwitch(n int) int {
	return int(math.Sqrt(float64(n)))
}
