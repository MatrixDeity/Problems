/**
  LeetCode_2359
  https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
  MatrixDeity, 2023.
*/

package leetcode2359

import "math"

func closestMeetingNode(edges []int, node1 int, node2 int) int {
	n := len(edges)
	dist1, dist2 := make([]int, n), make([]int, n)

	var impl func(dist []int, node int)
	impl = func(dist []int, node int) {
		for i := 0; i < len(dist); i++ {
			dist[i] = math.MaxInt
		}
		dist[node] = 0
		for edges[node] != -1 && dist[edges[node]] == math.MaxInt {
			dist[edges[node]] = dist[node] + 1
			node = edges[node]
		}
	}

	impl(dist1, node1)
	impl(dist2, node2)

	res := n
	maxDist := math.MaxInt

	for i := 0; i < n; i++ {
		dist := dist1[i]
		if dist2[i] > dist {
			dist = dist2[i]
		}
		if dist < maxDist {
			maxDist = dist
			res = i
		}
	}

	if res == n {
		return -1
	}
	return res
}
