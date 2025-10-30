/**
  LeetCode_547
  https://leetcode.com/problems/number-of-provinces/
  MatrixDeity, 2023.
*/

package leetcode547

func findCircleNum(isConnected [][]int) int {
	n := len(isConnected[0])
	res := 0
	visited := make([]bool, n)

	var impl func(v int)
	impl = func(v int) {
		visited[v] = true

		for i, ok := range isConnected[v] {
			if ok == 1 && !visited[i] {
				impl(i)
			}
		}
	}

	for i := 0; i < n; i++ {
		if !visited[i] {
			res++
			impl(i)
		}
	}

	return res
}
