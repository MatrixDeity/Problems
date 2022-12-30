/**
  LeetCode_797
  https://leetcode.com/problems/all-paths-from-source-to-target
  MatrixDeity, 2022.
*/

package leetcode797

func allPathsSourceTarget(graph [][]int) [][]int {
	res := [][]int{}
	curr := []int{}
	target := len(graph) - 1

	var impl func(node int)
	impl = func(node int) {
		curr = append(curr, node)
		defer func() {
			curr = curr[:len(curr)-1]
		}()

		if node == target {
			newPath := make([]int, len(curr))
			copy(newPath, curr)
			res = append(res, newPath)
			return
		}

		for _, n := range graph[node] {
			impl(n)
		}
	}

	impl(0)

	return res
}
