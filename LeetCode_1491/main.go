/**
  LeetCode_1491
  https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
  MatrixDeity, 2023.
*/

package leetcode1491

func average(salary []int) float64 {
	res := 0
	max, min := salary[0], salary[0]

	for _, num := range salary {
		res += num

		if min < num {
			min = num
		}

		if num < max {
			max = num
		}
	}

	res -= max + min

	return float64(res) / float64(len(salary)-2)
}
