/**
  LeetCode_947
  https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
  MatrixDeity, 2022.
*/

package leetcode947

func removeStones(stones [][]int) int {
	n := len(stones)
	toRemove := 0
	visited := make([]bool, n)

	var impl func(int)
	impl = func(i int) {
		visited[i] = true
		for j := range stones {
			streak := stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]
			if streak && !visited[j] {
				impl(j)
			}
		}
	}

	for i := range stones {
		if !visited[i] {
			impl(i)
			toRemove++
		}
	}

	return n - toRemove
}
