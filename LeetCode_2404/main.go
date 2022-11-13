/**
  LeetCode_2404
  https://leetcode.com/problems/most-frequent-even-element/
  MatrixDeity, 2022.
*/

package leetcode2404

func mostFrequentEven(nums []int) int {
	res := -1
	resCnt := 0
	counter := map[int]int{}

	for _, num := range nums {
		if num&1 == 0 {
			counter[num]++
			cnt := counter[num]
			if resCnt < cnt || (resCnt == cnt && num < res) {
				resCnt = cnt
				res = num
			}
		}
	}

	return res
}
