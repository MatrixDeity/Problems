/**
  LeetCode_208
  https://leetcode.com/problems/implement-trie-prefix-tree/
  MatrixDeity, 2023.
*/

package leetcode208

type Node struct {
	children map[byte]*Node
	isWord   bool
}

type Trie struct {
	root *Node
}

func NewNode() *Node {
	return &Node{
		children: make(map[byte]*Node),
		isWord:   false,
	}
}

func Constructor() Trie {
	return Trie{
		root: NewNode(),
	}
}

func (this *Trie) Insert(word string) {
	ptr := this.root

	for i := range word {
		if _, ok := ptr.children[word[i]]; !ok {
			ptr.children[word[i]] = NewNode()
		}

		ptr = ptr.children[word[i]]
	}

	ptr.isWord = true
}

func (this *Trie) Search(word string) bool {
	ptr := this.root

	for i := range word {
		if _, ok := ptr.children[word[i]]; !ok {
			return false
		}

		ptr = ptr.children[word[i]]
	}

	return ptr.isWord
}

func (this *Trie) StartsWith(prefix string) bool {
	ptr := this.root

	for i := range prefix {
		if _, ok := ptr.children[prefix[i]]; !ok {
			return false
		}

		ptr = ptr.children[prefix[i]]
	}

	return true
}
