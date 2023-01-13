/**
  LeetCode_2244
  https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
  MatrixDeity, 2023.
*/

package leetcode2244

func minimumRounds(tasks []int) int {
	counter := make(map[int]int)
	res := 0

	for _, num := range tasks {
		counter[num]++
	}

	for _, val := range counter {
		if val == 1 {
			return -1
		}

		if val%3 == 0 {
			res += val / 3
		} else {
			res += val/3 + 1
		}
	}

	return res
}
