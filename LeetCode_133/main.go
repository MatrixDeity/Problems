/**
  LeetCode_133
  https://leetcode.com/problems/clone-graph/
  MatrixDeity, 2023.
*/

package leetcode133

type Node struct {
	Val       int
	Neighbors []*Node
}

func cloneGraph(node *Node) *Node {
	if node == nil {
		return nil
	}

	nodes := make(map[*Node]*Node)

	var impl func(node *Node) *Node
	impl = func(node *Node) *Node {
		if _, ok := nodes[node]; !ok {
			nodes[node] = &Node{
				Val:       node.Val,
				Neighbors: make([]*Node, len(node.Neighbors)),
			}

			for i := range node.Neighbors {
				nodes[node].Neighbors[i] = impl(node.Neighbors[i])
			}
		}

		return nodes[node]
	}

	return impl(node)
}
