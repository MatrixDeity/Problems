/**
  LeetCode_2528
  https://leetcode.com/problems/maximize-the-minimum-powered-city/
  MatrixDeity, 2025.
*/

package leetcode2528

func maxPower(stations []int, r int, k int) int64 {
	n := len(stations)

	diffs := make([]int64, n+1)
	for i, val := range stations {
		diffs[max(i-r, 0)] += int64(val)
		diffs[min(i+r, n-1)+1] -= int64(val)
	}

	check := func(m int64) bool {
		tmp := append([]int64(nil), diffs...)

		var curr, count int64
		for i := 0; i < n; i++ {
			curr += tmp[i]
			if curr < m {
				need := m - curr
				count += need

				if count > int64(k) {
					return false
				}

				curr = m
				if i+2*r+1 < n {
					tmp[i+2*r+1] -= need
				}
			}
		}

		return true
	}

	prefix := make([]int64, n)
	prefix[0] = diffs[0]
	l := prefix[0]
	for i := 1; i < n; i++ {
		prefix[i] = prefix[i-1] + diffs[i]
		l = min(l, prefix[i])
	}
	h := int64(2e10)

	for l < h {
		m := (l + h + 1) / 2
		if check(m) {
			l = m
		} else {
			h = m - 1
		}
	}

	return l
}
