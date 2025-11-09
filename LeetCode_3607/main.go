/**
  LeetCode_3607
  https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/
  MatrixDeity, 2025.
*/

package leetcode3607

func processQueries(c int, connections [][]int, queries [][]int) []int {
	res := make([]int, 0)
	parents := make([]int, c+1)
	offlines := make([]bool, c+1)
	groups := make(map[int][]int)

	var findParents func(i int) int
	findParents = func(i int) int {
		if parents[i] == -1 {
			return i
		}

		parents[i] = findParents(parents[i])

		return parents[i]
	}

	for i := 0; i < len(parents); i++ {
		parents[i] = -1
	}

	for _, connection := range connections {
		a, b := findParents(connection[0]), findParents(connection[1])
		if a != b {
			parents[b] = a
		}
	}

	for i := 0; i < len(parents); i++ {
		p := findParents(i)
		groups[p] = append(groups[p], i)
	}

	for _, q := range queries {
		p := findParents(q[1])
		offline := offlines[q[1]]
		if q[0] == 1 {
			val := -1
			if !offline {
				val = q[1]
			} else {
				for len(groups[p]) > 0 {
					if offlines[groups[p][0]] {
						groups[p] = groups[p][1:]
					} else {
						val = groups[p][0]
						break
					}
				}
			}
			res = append(res, val)
		} else {
			offlines[q[1]] = true
		}
	}

	return res
}
