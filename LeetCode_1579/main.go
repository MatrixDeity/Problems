/**
  LeetCode_1579
  https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
  MatrixDeity, 2023.
*/

package leetcode1579

type UnionFind struct {
	parent []int
	count  int
}

func NewUnionFind(size int) *UnionFind {
	arr := make([]int, size)

	for i := 0; i < size; i++ {
		arr[i] = i
	}

	return &UnionFind{
		parent: arr,
		count:  size,
	}
}

func (u *UnionFind) Union(a, b int) bool {
	parentA := u.Find(a)
	parentB := u.Find(b)

	if parentA != parentB {
		u.parent[parentA] = parentB
		u.count--

		return true
	}

	return false
}

func (u *UnionFind) Find(x int) int {
	if u.parent[x] == x {
		return x
	}

	u.parent[x] = u.Find(u.parent[x])

	return u.parent[x]
}

func maxNumEdgesToRemove(n int, edges [][]int) int {
	res := 0

	alice := NewUnionFind(n)
	bob := NewUnionFind(n)

	for _, edge := range edges {
		if edge[0] == 3 {
			if !alice.Union(edge[1]-1, edge[2]-1) {
				res++
			}

			bob.Union(edge[1]-1, edge[2]-1)
		}
	}

	for _, edge := range edges {
		if edge[0] == 1 {
			if !alice.Union(edge[1]-1, edge[2]-1) {
				res++
			}
		}

		if edge[0] == 2 {
			if !bob.Union(edge[1]-1, edge[2]-1) {
				res++
			}
		}
	}

	if alice.count != 1 || bob.count != 1 {
		return -1
	}

	return res
}
