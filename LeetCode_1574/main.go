/**
  LeetCode_1574
  https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
  MatrixDeity, 2022.
*/

package leetcode1574

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func findLengthOfShortestSubarray(arr []int) int {
	n := len(arr)
	i, j := 0, n-1

	for ; i < n-1; i++ {
		if arr[i+1] < arr[i] {
			break
		}
	}

	if i == n-1 {
		return 0
	}

	for ; j > 0; j-- {
		if arr[j] < arr[j-1] {
			break
		}
	}

	res := min(j, n-1-i)

	j = n - 1
	for ; i >= 0; i-- {
		for arr[j-1] <= arr[j] && i < j-1 && arr[i] <= arr[j-1] {
			j--
		}
		if arr[i] <= arr[j] {
			res = min(res, j-i-1)
		}
	}

	return res
}
