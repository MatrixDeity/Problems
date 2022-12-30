/**
  LeetCode_841
  https://leetcode.com/problems/keys-and-rooms/
  MatrixDeity, 2022.
*/

package leetcode841

func canVisitAllRooms(rooms [][]int) bool {
	visited := make([]bool, len(rooms))

	var impl func(vert int)
	impl = func(vert int) {
		if visited[vert] {
			return
		}

		visited[vert] = true

		for _, v := range rooms[vert] {
			impl(v)
		}
	}

	impl(0)

	for i := range visited {
		if !visited[i] {
			return false
		}
	}
	return true
}
