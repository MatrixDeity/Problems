/**
  LeetCode_1345
  https://leetcode.com/problems/jump-game-iv/
  MatrixDeity, 2023.
*/

package leetcode1345

func minJumps(arr []int) int {
	res := 0
	mem := map[int][]int{}
	for i := 1; i < len(arr); i++ {
		mem[arr[i]] = append(mem[arr[i]], i)
	}

	visited := make([]bool, len(arr))
	visited[0] = true

	queue := []int{0}

	for len(queue) > 0 {
		n := len(queue)

		for i := 0; i < n; i++ {
			currIndex := queue[i]

			if currIndex == len(arr)-1 {
				return res
			}

			for _, index := range mem[arr[currIndex]] {
				if !visited[index] {
					visited[index] = true
					queue = append(queue, index)
				}
			}

			delete(mem, arr[currIndex])

			if currIndex != 0 && !visited[currIndex-1] {
				visited[currIndex-1] = true
				queue = append(queue, currIndex-1)
			}

			if !visited[currIndex+1] {
				visited[currIndex+1] = true
				queue = append(queue, currIndex+1)
			}
		}

		queue = queue[n:]
		res++
	}

	return -1
}
