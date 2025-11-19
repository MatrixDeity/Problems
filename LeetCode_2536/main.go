/**
  LeetCode_2536
  https://leetcode.com/problems/increment-submatrices-by-one/
  MatrixDeity, 2025.
*/

package leetcode2536

func rangeAddQueries(n int, queries [][]int) [][]int {
	diff := make([][]int, n+1)
	for i := range diff {
		diff[i] = make([]int, n+1)
	}

	for _, query := range queries {
		r1, c1, r2, c2 := query[0], query[1], query[2], query[3]

		diff[r1][c1]++
		diff[r1][c2+1]--
		diff[r2+1][c1]--
		diff[r2+1][c2+1]++
	}

	res := make([][]int, n)
	for i := range res {
		res[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			var up, left, diag int

			if i > 0 {
				up = diff[i-1][j]
			}
			if j > 0 {
				left = diff[i][j-1]
			}
			if i > 0 && j > 0 {
				diag = diff[i-1][j-1]
			}
			diff[i][j] = diff[i][j] + up + left - diag
			res[i][j] = diff[i][j]
		}
	}

	return res
}
