/**
  LeetCode_3234
  https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/
  MatrixDeity, 2025.
*/

package leetcode3234

func numberOfSubstrings(s string) int {
	c1 := make([]int, 1, len(s))
	var counts [2]int
	res := 0

	for _, c := range s {
		counts[c-'0']++
		if c == '0' {
			c1 = append(c1, counts[1])
		}

		res += counts[1] - c1[counts[0]]
		for c0 := counts[0] - 1; c0 >= 0; c0-- {
			num0 := counts[0] - c0
			sqr0 := num0 * num0

			if sqr0 > counts[1] {
				break
			}

			h := counts[1] - c1[c0]
			l := counts[1] - c1[c0+1]
			if h >= sqr0 {
				res += max(h-max(l, sqr0)+1, 0)
			}
		}
	}

	return res
}
