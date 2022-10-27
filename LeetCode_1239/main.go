/**
  LeetCode_1239
  https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
  MatrixDeity, 2022.
*/

package leetcode1239

type bitset uint32

func (bs bitset) count() int {
	tmp := bitset(1)
	counter := 0

	for i := 0; i < 32; i++ {
		if bs&tmp > 0 {
			counter++
		}
		tmp <<= 1
	}

	return counter
}

func (bs *bitset) set(bit byte) {
	tmp := bitset(1)
	tmp <<= bit
	*bs |= tmp
}

func maxLength(arr []string) int {
	dp := []bitset{bitset(0)}
	res := 0

	for _, s := range arr {
		var bs bitset
		for i := range s {
			bs.set(s[i] - 'a')
		}
		if bs.count() < len(s) {
			continue
		}

		for _, dpBs := range dp {
			if dpBs&bs > 0 {
				continue
			}

			newBs := bs | dpBs
			dp = append(dp, newBs)

			n := newBs.count()
			if n > res {
				res = n
			}
		}
	}

	return res
}
