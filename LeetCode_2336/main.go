/**
  LeetCode_2336
  https://leetcode.com/problems/smallest-number-in-infinite-set/
  MatrixDeity, 2023.
*/

package leetcode2336

type SmallestInfiniteSet struct {
	smallest int
	removed  map[int]struct{}
}

func Constructor() SmallestInfiniteSet {
	return SmallestInfiniteSet{
		smallest: 1,
		removed:  make(map[int]struct{}),
	}
}

func (this *SmallestInfiniteSet) PopSmallest() int {
	res := this.smallest
	this.removed[res] = struct{}{}

	for num := this.smallest + 1; ; num++ {
		if _, ok := this.removed[num]; !ok {
			this.smallest = num
			break
		}
	}

	return res
}

func (this *SmallestInfiniteSet) AddBack(num int) {
	if num < this.smallest {
		this.smallest = num
	}

	delete(this.removed, num)
}
