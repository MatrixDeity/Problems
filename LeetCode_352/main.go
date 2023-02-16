/**
  LeetCode_352
  https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/
  MatrixDeity, 2023.
*/

package leetcode352

const (
	maxNum int = 10001
)

type SummaryRanges struct {
	nums []bool
}

func Constructor() SummaryRanges {
	return SummaryRanges{
		nums: make([]bool, maxNum),
	}
}

func (this *SummaryRanges) AddNum(value int) {
	this.nums[value] = true
}

func (this *SummaryRanges) GetIntervals() [][]int {
	res := make([][]int, 0)
	lo, hi := -1, -1

	for i := range this.nums {
		if !this.nums[i] {
			if lo != -1 {
				res = append(res, []int{lo, hi})
				lo, hi = -1, -1
			}
			continue
		}

		if lo == -1 {
			lo, hi = i, i
			continue
		}

		hi = i
	}

	return res
}
