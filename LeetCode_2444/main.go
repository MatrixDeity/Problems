/**
  LeetCode_2444
  https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
  MatrixDeity, 2023.
*/

package leetcode2444

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func countSubarrays(nums []int, minK int, maxK int) int64 {
	res := int64(0)
	currMin, currMax := -1, -1
	outIndex := 0

	for i, num := range nums {
		if num < minK || num > maxK {
			outIndex = i + 1
			currMin, currMax = -1, -1
			continue
		}

		if num == minK {
			currMin = i
		}

		if num == maxK {
			currMax = i
		}

		if currMin != -1 && currMax != -1 {
			res += int64(min(currMin, currMax) - outIndex + 1)
		}
	}

	return res
}
