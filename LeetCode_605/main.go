/**
  LeetCode_605
  https://leetcode.com/problems/can-place-flowers/
  MatrixDeity, 2023.
*/

package leetcode605

func canPlaceFlowers(flowerbed []int, n int) bool {
	for i := range flowerbed {
		isEmpty := flowerbed[i] == 0
		isLeftEmpty := i == 0 || flowerbed[i-1] == 0
		isRightEmpty := i == len(flowerbed)-1 || flowerbed[i+1] == 0

		if isEmpty && isLeftEmpty && isRightEmpty {
			n--
			flowerbed[i] = 1
		}

		if n <= 0 {
			return true
		}
	}

	return false
}
