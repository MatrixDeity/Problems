/**
  LeetCode_1572
  https://leetcode.com/problems/matrix-diagonal-sum/
  MatrixDeity, 2023.
*/

package leetcode59

func generateMatrix(n int) [][]int {
	res := make([][]int, n)
	for i := range res {
		res[i] = make([]int, n)
	}

	l, r, t, b := 0, n-1, 0, n-1
	cnt, sqr := 1, n*n

	for cnt <= sqr {
		for i := l; i <= r; i++ {
			res[t][i] = cnt
			cnt++
		}
		t++

		for i := t; i <= b; i++ {
			res[i][r] = cnt
			cnt++
		}
		r--

		if t > b || l > r {
			break
		}

		for i := r; i >= l; i-- {
			res[b][i] = cnt
			cnt++
		}
		b--

		for i := b; i >= t; i-- {
			res[i][l] = cnt
			cnt++
		}
		l++
	}

	return res
}
